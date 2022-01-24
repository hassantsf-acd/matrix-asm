; void assign(int[][] dest, int[][] src, int row, int col) 
%define DEST [ebp + 8]
%define SRC [ebp + 12]
%define ASSIGN_COL [ebp + 20]
%define ASSIGN_ROW [ebp + 16]
assign_matrix:
    push ebp
    mov ebp, esp

    mov esi, 0
assign_loop1:
    mov edi, 0
assign_loop2:
    mov ebx, SRC
    mov eax, ASSIGN_COL
    mul esi
    add eax, edi
    mov ecx, [ebx + 4 * eax]

    mov ebx, DEST
    mov eax, ASSIGN_COL
    mul esi
    add eax, edi
    mov [ebx + 4 * eax], ecx

    
    inc edi
    cmp edi, ASSIGN_COL
    jl assign_loop2

    inc esi
    cmp esi, ASSIGN_ROW
    jl assign_loop1



    mov esp, ebp
    pop ebp
    ret 16

assign_B_from_A:
    mov edx, [row_A]
    mov [row_B], edx
    mov edx, [col_A]
    mov [col_B], edx
    push dword [col_B]
    push dword [row_B]
    push A
    push B
    call assign_matrix
    ret

assign_A_from_B:
    mov edx, [row_B]
    mov [row_A], edx
    mov edx, [col_B]
    mov [col_A], edx
    push dword [col_A]
    push dword [row_A]
    push B
    push A
    call assign_matrix
    ret

assign_C_to_A:
    push dword [col_C]
    push dword [row_C]
    push C
    push A
    call assign_matrix
    ret

assign_C_to_B:
    push dword [col_C]
    push dword [row_C]
    push C
    push B
    call assign_matrix
    ret
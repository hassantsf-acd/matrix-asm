read_A:
    mov eax, A_msg
    call print_string

    push col_A
    push row_A
    call read_row_col

    push dword [col_A]
    push dword [row_A]
    push A
    call read_matrix
    ret

read_B:
    mov eax, B_msg
    call print_string

    push col_B
    push row_B
    call read_row_col

    push dword [col_B]
    push dword [row_B]
    push B
    call read_matrix
    ret

; void read_matrix(int[][] matrix, int row, int col)
read_matrix:
    push ebp
    mov ebp, esp

    mov ebx, MATRIX
    mov esi, 0
read_loop1:
    mov edi, 0
read_loop2:
    mov eax, COL
    mul esi
    add eax, edi
    mov ecx, eax

    call read_int
    mov [ebx + 4 * ecx], eax

    inc edi
    cmp edi, COL
    jl read_loop2

    inc esi
    cmp esi, ROW
    jl read_loop1

    mov esp, ebp
    pop ebp
    ret 12

read_row_col:
    push ebp
    mov ebp, esp

    mov ecx, [ebp + 8]
    mov eax, row_msg
    call print_string
    call read_int
    mov [ecx], eax

    mov ecx, [ebp + 12]
    mov eax, col_msg
    call print_string
    call read_int
    mov [ecx], eax

    mov esp, ebp
    pop ebp
    ret 8
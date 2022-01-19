; void sum(int[][] A, int[][] B, int row, int col) 
%define SUM_ROW [ebp + 20]
%define SUM_COL [ebp + 16]
sum_matrix:
    push ebp
    mov ebp, esp

    mov ecx, SUM_ROW
    mov [row_C], ecx
    mov ecx, SUM_COL
    mov [col_C], ecx

    mov esi, 0
sum_loop1:
    mov edi, 0
sum_loop2:

    mov ebx, A_MATRIX
    mov eax, SWAP_COL
    mul esi
    add eax, edi
    mov ecx, [ebx + 4 * eax]

    mov ebx, B_MATRIX
    mov eax, SWAP_COL
    mul esi
    add eax, edi
    add ecx, [ebx + 4 * eax]

    mov ebx, C
    mov eax, SWAP_COL
    mul esi
    add eax, edi
    mov [ebx + 4 * eax], ecx

    
    inc edi
    cmp edi, SWAP_COL
    jl sum_loop2

    inc esi
    cmp esi, SWAP_ROW
    jl sum_loop1



    mov esp, ebp
    pop ebp
    ret 16
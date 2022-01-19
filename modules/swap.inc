; void swap(int[][] A, int[][] B, int row, int col) 
%define SWAP_ROW [ebp + 20]
%define SWAP_COL [ebp + 16]
swap_matrix:
    push ebp
    mov ebp, esp

    mov esi, 0
swap_loop1:
    mov edi, 0
swap_loop2:

    mov ebx, A_MATRIX
    mov eax, SWAP_COL
    mul esi
    add eax, edi
    mov ecx, [ebx + 4 * eax]

    mov ebx, B_MATRIX
    mov eax, SWAP_COL
    mul esi
    add eax, edi
    mov edx, [ebx + 4 * eax]
    mov [var1], edx


    mov [ebx + 4 * eax], ecx

    mov ebx, A_MATRIX
    mov eax, SWAP_COL
    mul esi
    add eax, edi
    mov edx, [var1]
    mov [ebx + 4 * eax], edx

    
    inc edi
    cmp edi, SWAP_COL
    jl swap_loop2

    inc esi
    cmp esi, SWAP_ROW
    jl swap_loop1



    mov esp, ebp
    pop ebp
    ret 20
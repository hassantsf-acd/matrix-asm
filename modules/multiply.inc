; void multiply(int[][] A, int[][] B, int row1, int row2, int col2)
multiply_matrix:
    push ebp
    mov ebp, esp

    mov esi, 0
multiply_loop1:
    mov edi, 0
multiply_loop2:

    mov dword [sum], 0
    mov dword [k], 0
multiply_loop3:
    mov ebx, A_MATRIX
    mov eax, ROW2
    mul esi
    add eax, [k]
    mov eax, [ebx + 4 * eax]
    mov [var1], eax


    mov ebx, B_MATRIX
    mov eax, COL2
    mul dword [k]
    add eax, edi
    mov eax, [ebx + 4 * eax]
    mov [var2], eax


    imul dword [var1]
    add [sum], eax
    

    inc dword [k]
    mov eax, ROW2
    cmp [k], eax
    jl multiply_loop3

    
    mov ebx, C
    mov eax, COL2
    mul esi
    add eax, edi
    mov edx, [sum]
    mov [ebx + 4 * eax], edx

    inc edi
    cmp edi, COL2
    jl multiply_loop2

    inc esi
    cmp esi, ROW1
    jl multiply_loop1



    mov esp, ebp
    pop ebp
    ret 20
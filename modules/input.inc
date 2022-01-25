read_A:
    push col_A
    push row_A
    call read_row_col


    cmp dword [row_A], 0
    jg end_read_A_if_col
    mov eax, negative_dimension_msg
    call print_string
    ret
end_read_A_if_row:
    cmp dword [col_A], 0
    jg end_read_A_if_col
    mov eax, negative_dimension_msg
    call print_string
    ret
end_read_A_if_col:

    mov eax, A_msg
    call print_string
    push dword [col_A]
    push dword [row_A]
    push A
    call read_matrix
    ret

read_B:
    push col_B
    push row_B
    call read_row_col

    cmp dword [row_B], 0
    jg end_read_B_if_col
    mov eax, negative_dimension_msg
    call print_string
    ret
end_read_B_if_row:
    cmp dword [col_B], 0
    jg end_read_B_if_col
    mov eax, negative_dimension_msg
    call print_string
    ret
end_read_B_if_col:

    mov eax, B_msg
    call print_string


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
    cmp eax, 0
    jg end_if1
    mov eax, 0
end_if1:
    mov [ecx], eax

    mov ecx, [ebp + 12]
    mov eax, col_msg
    call print_string
    call read_int

    cmp eax, 0
    jg end_if2
    mov eax, 0
end_if2:
    mov [ecx], eax

    mov eax, [row_A]
    call print_int
    call print_nl


    mov esp, ebp
    pop ebp
    ret 8
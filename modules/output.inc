print_A:
    mov eax, A_msg
    call print_string
    push dword [col_A]
    push dword [row_A]
    push A
    call print_matrix
    ret

print_B:
    mov eax, B_msg
    call print_string
    push dword [col_B]
    push dword [row_B]
    push B
    call print_matrix
    ret

; =====================================================



; =====================================================

print_matrix:
    push ebp
    mov ebp, esp

    mov ebx, MATRIX
    mov esi, 0
print_loop1:
    mov edi, 0
print_loop2:
    mov eax, COL
    mul esi
    add eax, edi
    mov ecx, eax

    mov eax, [ebx + 4 * ecx]
    call print_int

    mov al, 32
    call print_char

    inc edi
    cmp edi, COL
    jl print_loop2

    call print_nl
    inc esi
    cmp esi, ROW
    jl print_loop1



    mov esp, ebp
    pop ebp
    ret 12
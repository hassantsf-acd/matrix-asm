swap_matrix:
    mov edx, [row_A]
    mov [row_C], edx
    mov edx, [col_A]
    mov [col_C], edx
    push dword [col_A]
    push dword [row_A]
    push A
    push C
    call assign_matrix
    
    mov edx, [row_B]
    mov [row_A], edx
    mov edx, [col_B]
    mov [col_A], edx
    push dword [col_B]
    push dword [row_B]
    push B
    push A
    call assign_matrix

    mov edx, [row_C]
    mov [row_B], edx
    mov edx, [col_C]
    mov [col_B], edx
    push dword [col_C]
    push dword [row_C]
    push C
    push B
    call assign_matrix

    ret

;     mov esi, 0
; swap_loop1:
;     mov edi, 0
; swap_loop2:

;     mov ebx, A_MATRIX
;     mov eax, SWAP_COL
;     mul esi
;     add eax, edi
;     mov ecx, [ebx + 4 * eax]

;     mov ebx, B_MATRIX
;     mov eax, SWAP_COL
;     mul esi
;     add eax, edi
;     mov edx, [ebx + 4 * eax]
;     mov [var1], edx


;     mov [ebx + 4 * eax], ecx

;     mov ebx, A_MATRIX
;     mov eax, SWAP_COL
;     mul esi
;     add eax, edi
;     mov edx, [var1]
;     mov [ebx + 4 * eax], edx

    
;     inc edi
;     cmp edi, SWAP_COL
;     jl swap_loop2

;     inc esi
;     cmp esi, SWAP_ROW
;     jl swap_loop1



    mov esp, ebp
    pop ebp
    ret 16
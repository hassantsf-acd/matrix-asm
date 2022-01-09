%include "asm_io.inc"
segment .data
A: times 25 * 25 dd 0
B: times 25 * 25 dd 0
row_A: dd 0
col_A: dd 0
row_B: dd 0
col_B: dd 0
; Messages
row_msg: db "Enter row size = ", 0
col_msg: db "Enter column size = ", 0
A_msg: db "Matrix A:", 10, 0
B_msg: db "Matrix B:", 10, 0

%define MATRIX [ebp+8]
%define ROW [ebp+12]
%define COL [ebp+16]

segment .text
global asm_main

asm_main:
    enter 0, 0
    pusha

    call read_A
    call print_A

    popa
    leave
    ret

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
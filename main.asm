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

%include "modules.inc"
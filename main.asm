%include "asm_io.inc"
segment .data
A: times 25 * 25 dd 0
B: times 25 * 25 dd 0
C: times 25 * 25 dd 0
row_A: dd 0
col_A: dd 0
row_B: dd 0
col_B: dd 0
; Messages
row_msg: db "Enter row size = ", 0
col_msg: db "Enter column size = ", 0
A_msg: db "Matrix A:", 10, 0
B_msg: db "Matrix B:", 10, 0
; Helper Variables
sum: dd 0
k: dd 0
var1: dd 0
var2: dd 0

%define MATRIX [ebp+8]
%define ROW [ebp+12]
%define COL [ebp+16]

%define A_MATRIX [ebp+8]
%define B_MATRIX [ebp+12]
%define ROW1 [ebp+16]
%define ROW2 [ebp+20]
%define COL2 [ebp+24]

segment .text
global asm_main

asm_main:
    enter 0, 0
    pusha

    call read_A
    call read_B

    push dword [col_A]
    push dword [row_A]
    push B
    push A
    call swap_matrix

    call print_A

    call print_B

    popa
    leave
    ret

%include "modules.inc"
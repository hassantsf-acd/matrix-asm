%include "asm_io.inc"
segment .data
A: times 25 * 25 dd 0
B: times 25 * 25 dd 0
C: times 25 * 25 dd 0
row_A: dd 0
col_A: dd 0
row_B: dd 0
col_B: dd 0
row_C: dd 0
col_C: dd 0
%include "modules/messages.inc"
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

segment .text
global asm_main

asm_main:
    enter 0, 0
    pusha

    call menu

    popa
    leave
    ret

%include "modules.inc"
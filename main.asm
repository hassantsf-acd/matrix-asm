%include "asm_io.inc"
segment .text
global asm_main

asm_main:
    enter 0, 0
    pusha


    popa
    leave
    ret
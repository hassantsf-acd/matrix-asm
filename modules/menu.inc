menu:
    mov eax, choose_optoion_msg
    call print_string
    mov eax, option1_msg
    call print_string
    mov eax, option2_msg
    call print_string
    mov eax, option3_msg
    call print_string
    mov eax, option4_msg
    call print_string
    mov eax, option5_msg
    call print_string
    mov eax, option6_msg
    call print_string
    mov eax, option7_msg
    call print_string
    mov eax, option8_msg
    call print_string
    mov eax, option9_msg
    call print_string
    mov eax, option10_msg
    call print_string
    mov eax, option11_msg
    call print_string
    mov eax, exit_menu_msg
    call print_string
    call read_int
    call print_nl
    call print_nl
    cmp eax, 12
    je end_menu

    cmp eax, 1
    jne end_case1
    call case1
    jmp menu_loop
end_case1:

    cmp eax, 2
    jne end_case2
    call case2
    jmp menu_loop
end_case2:

    cmp dword [valid_A], 0
    jne end_print_if_A
    mov eax, init_msg
    call print_string
    jmp menu_loop
end_print_if_A:

    cmp eax, 3
    jne end_case3
    call case3
    jmp menu_loop
end_case3:

    cmp dword [valid_B], 0
    jne end_print_if_B
    mov eax, init_msg
    call print_string
    jmp menu_loop
end_print_if_B:

    cmp eax, 4
    jne end_case4
    call case4
    jmp menu_loop
end_case4:

    cmp dword [valid_A], 0
    jne end_init_if_A
    mov eax, init_msg
    call print_string
    jmp menu_loop
end_init_if_A:
    cmp dword [valid_B], 0
    jne end_init_if_B
    mov eax, init_msg
    call print_string
    jmp menu_loop
end_init_if_B:


    cmp eax, 5
    jne end_case5
    call case5
    jmp menu_loop
end_case5:

    cmp eax, 6
    jne end_case6
    call case6
    jmp menu_loop
end_case6:

    cmp eax, 7
    jne end_case7
    call case7
    jmp menu_loop
end_case7:

    cmp eax, 8
    jne end_case8
    call case8
    jmp menu_loop
end_case8:

    cmp eax, 9
    jne end_case9
    call case9
    jmp menu_loop
end_case9:

    cmp eax, 10
    jne end_case10
    call case10
    jmp menu_loop
end_case10:

    cmp eax, 11
    jne end_case11
    call case11
    jmp menu_loop
end_case11:

menu_loop:
    call print_nl
    call print_nl
    jmp menu
end_menu:
    ret

case1:
    call read_A
    ret

case2:
    call read_B
    ret

case3:
    call print_A
    ret

case4:
    call print_B
    ret

case5:
    call A_A_multiply_B
    ret

case6:
    call B_A_multiply_B
    ret

case7:
    call A_B_multiply_A
    ret

case8:
    call B_B_multiply_A
    ret

case9:
    call swap_matrix
    ret

case10:
    call assign_A_from_B
    ret

case11:
    call assign_B_from_A
    ret
menu:
menu_loop:
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
    mov eax, exit_menu_msg
    call print_string
    call read_int
    cmp eax, 10
    jne menu_loop
    ret
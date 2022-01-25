; Menu Options
choose_optoion_msg: db "Please choose options below:", 10, 0
option1_msg: db "1) Read A", 10, 0
option2_msg: db "2) Read B", 10, 0
option3_msg: db "3) A = A * B", 10, 0
option4_msg: db "4) B = A * B", 10, 0
option5_msg: db "5) A = B * A", 10, 0
option6_msg: db "6) B = B * A", 10, 0
option7_msg: db "7) Swap(A, B)", 10, 0
option8_msg: db "8) A = B", 10, 0
option9_msg: db "9) B = A", 10, 0
option10_msg: db "10) Print A", 10, 0
option11_msg: db "11) Print B", 10, 0
exit_menu_msg: db "12) Exit", 10, 0

; Input Messages
row_msg: db "Enter row size = ", 0
col_msg: db "Enter column size = ", 0
; Output Messages
A_msg: db "Matrix A:", 10, 0
B_msg: db "Matrix B:", 10, 0

; Errors
negative_dimension_msg: db "Invalid dimension for matrix", 10, 0
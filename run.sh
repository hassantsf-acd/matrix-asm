clear
nasm -f elf -d ELF_TYPE asm_io.asm
gcc -m32 -c driver.c
nasm -f elf $1.asm
gcc -m32 driver.o $1.o asm_io.o
./a.out
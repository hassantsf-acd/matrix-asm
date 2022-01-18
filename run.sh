clear
nasm -f elf -d ELF_TYPE asm_io.asm -o ./output/asm_io.o
gcc -m32 -c driver.c -o ./output/driver.o
nasm -f elf $1.asm -o ./output/$1.o
gcc -m32 ./output/driver.o ./output/$1.o  ./output/asm_io.o -o ./output/run.out
./output/run.out
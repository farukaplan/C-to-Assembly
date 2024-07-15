# C to Assembly

Some C to Assembly (x86_64) exercises. There are also inline assembly code examples given.

## Requeriments
- Bash shell (any linux distro) or WSL
- gcc for .c files
- nasm for .asm files

## Build 
```sh
# For .c files
gcc -o file_name file_name.c
```

```sh
# For .asm files
nasm -f elf64 -o file_name.o file_name.asm
ld -o file_name file_name.o
```

## Run
```sh
# For .c and .asm files
./file_name
```

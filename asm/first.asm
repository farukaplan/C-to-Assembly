;nasm -f elf64 -o output.o first.asm
;ld -o output output.o
;./output

section .data
    numbers dq 321762410, 9, 2943018, 0, 19371039, 18, -76241, -208424

section .text
    global _start
_start:

    mov rax, [numbers]
    mov r15, 0
loop:   
    mov rbx, 10         
    mov rcx, buffer     
    sub rdx, rdx        
    mov rdi, 10          
    cmp rax, 0
    jge Else
    mov dl, 45
    mov [rcx], dl
    neg rax
    jmp write9digits
    Else:
    mov dl, 32
    mov [rcx], dl
    write9digits:
        xor rdx, rdx    
        div rbx        
        add dl, '0'     
        mov [rcx+rdi], dl  
        dec rdi         
        cmp rdi, 1      
        jne write9digits   
    mov dl, 10
    mov [rcx + 11], dl
    mov rax, 1          
    mov rdi, 1          
    mov rsi, buffer     
    mov rdx, 12          
    syscall
    inc r15
    mov rax, [numbers + r15*8]          
    cmp r15, 8
    jne loop
    
    mov rax, 60         
    xor rdi, rdi        
    syscall           

section .bss
    buffer resb 12      

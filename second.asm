;nasm -f elf64 -o output.o second.asm
;ld -o output output.o
;./output

section .bss
	buffer: resb 31

section .text

	global _start
_start:
	mov r13, 0				; r13 = y, outerLoop counter

.outerLoop:
	mov rax, r13			
	sub rax, 15				; rax = rax - radius
	mov rdi, rax			
	call _abs
	mov rax, rdx			; rax = rdx = deltaY
	xor rdx, rdx			
	mov r12, 0				; r12 = x, innerLoop counter
	mov rcx, buffer

.innerLoop:
	mov rbx, r12			
	sub rbx, 15				; rbx = rbx - 15
	mov rdi, rbx			
	call _abs
	mov rbx, rdx			; rbx = rdx = deltaX
	xor rdx, rdx			
	mov rdx, rax			
	add rdx, rbx			; dist = deltaY + deltaX
	xor rbx, rbx
	cmp rdx, 4				
	jle .else				; if dist <= minimumDistance, jump to else
	mov r15, 60
	add rdx, r15			; rdx += 60
	mov [rcx], rdx			
	jmp .done
.else:
	mov dl, 32 
	mov [rcx], dl			; add space into rcx
.done:
	inc r12					; x++
	lea rcx, [rcx + 1]	
	cmp r12, 31				
	jl .innerLoop			; if x < size, jump innerLoop

	mov dl, 10				
	mov [rcx], dl			; add new line end of the rcx 
	mov rax, 1
	mov rdi, 1
	mov rsi, buffer
	mov rdx, 32
	syscall					; print everything in rcx
	xor rcx, rcx			
	inc r13					; y++
	cmp r13, 31				
	jl .outerLoop			; if y < size, jump outerLoop

	mov rax, 60
	mov rdi, rdi
	syscall					; syscall for exit

	global abs
_abs: 
	cmp rdi, 0				
	jg .positive			; if z > 0, jump positive
	neg rdi					; z = -z
	mov rdx, rdi
	ret
.positive:					
	mov rdx, rdi
	ret

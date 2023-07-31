// Name: Faruk
// Surname: KAPLAN
// Student ID: 21050111026

#include <stdio.h>

#define abs(z) (z > 0 ? (z) : -(z))
#define minimumDistance 4
#define charOffset  60

int main()
{
    int radius = 15;
    int size = 2 * radius + 1;
    int y = 0;
    
outerLoop: 
    {
        int deltaY = abs(y - radius);
        int x = 0;

        innerLoop:
        {
            int deltaX = abs(x - radius);
            int dist = deltaX + deltaY;

            int test = dist > minimumDistance;
            if (!test) goto Else;
                putchar(dist + charOffset);
                goto done;
            Else:
                putchar(' ');
            done:
                x++;
                if(x < size) goto innerLoop;
        }
        
        putchar(10);
        y++;
        if(y < size) goto outerLoop;
    }

    return 0;
}

/*
; Name: Faruk 
; Surname: KAPLAN
; Student ID: 21050111026

section .text

	global abs
_abs: 
	cmp rdi, 0			; compare z with 0
	jge .positive
	neg rdi				; z = -z
	ret
.positive:				; jump here if z > 0
	ret

	global _start
_start:
	mov r13, 0			; r13 = y, outerLoop counter

.outerLoop:
	mov rax, r13		; rax = y
	sub rax, 15			; rax = rax - radius
	mov rdi, rax		; rdi = rax
	call _abs
	mov rax, rdi		; rax = rdi = deltaY
	xor rdi, rdi		; clear rdi register
	mov r12, 0			; r12 = x, innerLoop counter

.innerLoop:
	mov rbx, r12		; rbx = x
	sub rbx, 15			; rbx = rbx - 15
	mov rdi, rbx		; rdi = rax
	call _abs
	mov rbx, rdi		; rbx = rdi = deltaX
	xor rdi, rdi		; clear rdi register
	mov rcx, rax		; rcx = rax
	add rcx, rbx		; dist = deltaY + deltaX
	xor rbx, rbx
	cmp rcx, 4			; compare dist and minimumDistance
	jne .else
	mov rbx, 60			; rbx = 60
	add rcx, rdx		; dist += 60
	mov rax, 1
	mov rdi, 1
	mov rdx, 12
	syscall
	xor rcx, rcx
	jmp .done
.else:
	mov rcx, 32			; print space
	mov rax, 1
	mov rdi, 1
	mov rdx, 12
	syscall
	xor rcx, rcx
.done:
	inc r12				; x++
	cmp r12, 31			; compare x with size
	jl .innerLoop

	mov rcx, 10
	mov rax, 1
	mov rdi, 1
	mov rdx, 12
	syscall
	xor rcx, rcx
	inc r13				; y++
	cmp r13, 31			; compare y with size
	jl .outerLoop

	mov rax, 60
	mov rdi, rdi
	syscall



	
	
*/
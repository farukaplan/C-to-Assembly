; Name: Faruk
; Surname: KAPLAN
; Student ID: 21050111026
		  
		  
		  global    _start

          section   .text
_start:   
		  
		  mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rdx, 1                  ; number of bytes
		  
	
		  mov   	r12, [n]			    ; n, assigned with 6
		  mov		r13, 1					; r13 = a
		  
whileLoop:
		  
		  mov		r14, 64					; r14 = 64
		  add		r14, r12				; r14 += n
		  	
		  mov r15, 0						; r15 = j
forLoop:	
		 
		  push		r14
          mov       rsi, rsp   	            ; use char on stack
          syscall                           ; invoke operating system to do the write
		  add       rsp, 8					; restore stack pointer	

		  inc r15							; j++;
		  cmp r15, r13						; compare j with a
		  jl forLoop						; jump forLoop if j < a

		  
		  mov       rsi, newline			; address of newline character to output
		  syscall							; invoke operating system to do the write

		  sal r13, 1						; a *= 2
		  dec r12							; n--
		  cmp r12, 0						; compare n with 0
		  jg whileLoop						; jump whileLoop if n > 0
		  
          mov       rax, 60                 ; system call for exit
          xor       rdi, rdi                ; exit code 0  (rdi = 0)
          syscall                           ; invoke operating system to exit

          section   .data
newline:  db        10      				; enter symbol
n: 		  db		6						; number of lines

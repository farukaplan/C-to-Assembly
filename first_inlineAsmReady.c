
#include <stdio.h>

void write9digits(int number) {
    
	int digits = 100000000;
    int digit = 0;
    char space = ' ';
    
    if (number >= 0) {
		asm volatile(
			"mov $1, %%rax\n\t"
			"mov $1, %%rdi\n\t"
			"mov %0, %%rsi\n\t"             // putchar(' ');
			"mov $1, %%rdx\n\t"
			"syscall"
			: 
			: "r" (&space)
			: "%rax", "%rdi", "%rsi", "%rdx"
        );
    } else {
        putchar('-');

        asm volatile(
			"negq %0"
        	: "+m" (digits)					// digits = -digits;
        	:
        	: "cc"
        );
    }
    
    for (int i=0; i<9; i++) {
		asm volatile(
			"cdq\n"             
			"idiv %2\n"         
			"mov %0, %%eax\n"   
			: "=r" (digit)      			 // digit = (number / digits);
			: "a" (number),     
			"r" (digits)      
			: "edx"             
        );

        putchar(digit + 48);

		asm volatile(
			"movl %0, %%eax;"    
			"cltd;"              
			"idivl %1;"          
			"movl %%edx, %0;"    			  // number = number % digits;
			: "=m" (number)
			: "m" (digits)
			: "%eax", "%edx"
		);

		asm volatile(
			"movl %0, %%eax;"       
			"cltd;"                  
			"movl $10, %%ebx;"       
			"idivl %%ebx;"          		   // digits /= 10;
			"movl %%eax, %0;"       
			: "=m" (digits)
			: "m" (digits)
			: "%eax", "%ebx", "%edx"
        );
    }
    putchar(10);
}

int main()
{
    const int numberCount = 8;
    int numbers[] = {321762410, 9, 2943018, 0, 19371039, 18, -76241, -208424};

    for (int k=0; k<numberCount; k++) {
        write9digits(numbers[k]);
    }

    return 0;
}
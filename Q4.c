// Name: Faruk
// Surname: KAPLAN
// Student ID: 21050111026

#include <stdio.h>

int main()
{
    int n = 6;
    int a = 1;

    whileLoop :
    {
		char symbol = 64 + n;
		int j = 0;
        forLoop: 
        {
            putchar(symbol);
            j++;
        }
        if(j < a) goto forLoop;

        putchar(10);
        
		a *= 2;
		n--;
    }
    if(n > 0) goto whileLoop;
    
    return 0;
}

//gcc -o output third.c
//./output

#include <stdio.h>

int main()
{
    int n = 6;
    int a = 1;
    while (n > 0) {
		char symbol = 64 + n;
		
        for (int j=0; j<a; j++) {
            putchar(symbol);
        }

        putchar(10);
        
		a *= 2;
		n--;
    }
    
    return 0;
}

//gcc -o output first_asmReady2.c
//./output

#include <stdio.h>

int main() {
    const int numberCount = 8;
    int numbers[] = {321762410, 9, 2943018, 0, 19371039, 18, -76241, -208424};
    
    int k = 0;
    loopOuter:
        int number = numbers[k];
        
        int digits = 100000000;
    
        if(number < 0) goto Else;
            putchar(' ');
        goto done;
        Else:
            putchar('-');
            digits = -digits;
        done:
        int i = 0;
        loop:
            int digit = (number / digits);
            putchar(digit + 48);
            
            number = number % digits;
            digits /= 10;
            i++;
        if(i<9) goto loop;
    
        putchar(10);        
        
        k++;
    if (k < numberCount) goto loopOuter;

    return 0;
}

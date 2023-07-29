#include <stdio.h>

void write9digits(int number) {
    
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
    if (i < 9) goto loop;

    putchar(10);
}

int main() {
    const int numberCount = 8;
    int numbers[] = {321762410, 9, 2943018, 0, 19371039, 18, -76241, -208424};
    
    int k = 0;
    loop:
        write9digits(numbers[k]);
        k++;
    if (k < numberCount) goto loop;

    return 0;
}

#include <stdio.h>

void write9digits(int number) {
    
    int digits = 100000000;
    
    if (number >= 0)
        putchar(' ');
    else {
        putchar('-');
        digits = -digits;
    }
    
    for (int i=0; i<9; i++) {
        int digit = (number / digits);
        putchar(digit + 48);
        
        number = number % digits;
        digits /= 10;
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

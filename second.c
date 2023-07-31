//gcc -o output first_asmReady1.c
//./output

#include <stdio.h>

#define abs(z) (z > 0 ? (z) : -(z))
#define minimumDistance 4
#define charOffset  60

int main()
{
    int radius = 15;
    int size = 2 * radius + 1;
    
    for (int y=0; y<size; y++) {
        int deltaY = abs(y - radius);

        for (int x=0; x<size; x++) {
            int deltaX = abs(x - radius);

            int dist = deltaX + deltaY;
            if (dist > minimumDistance)
                putchar(dist + charOffset);
            else
                putchar(' ');
        }
        
        putchar(10);
    }

    return 0;
}

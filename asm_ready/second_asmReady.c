//gcc -o output second_asmReady.c
//./output


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

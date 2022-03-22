#include <stdio.h>
#include <conio.h>
#include<windows.h>
#include<time.h>
#include <stdlib.h>
int main()
{
    int i, j, noframes, x, x1 = 10, x2;
    srand(time(0));
    for (i = 0; i < 200; i++)
        rand();
    noframes = rand() / 200;
    i = 1;
    j = 1;
    noframes = noframes / 8;
    printf("Number of frames is %d", noframes);
    while (noframes > 0)
    {
        printf("\nSending frame %d", i);
        srand(x1++);
        x = rand() % 10;
        if (x % 2 == 0)
        {
            for (x2 = 1; x2 < 2; x2++)
            {
                printf("\nWaiting for %d seconds\n", x2);
                Sleep(x2);
                Sleep(1000);
            }
            printf("\nSending frame %d", i);
            srand(x1++);
            x = rand() % 10;
        }
        printf("\nAck for frame %d", j);
        noframes -= 1;
        i++;
        j++;
    }
    printf("\n End of Stop and Wait protocol");
    getch();
    return 0;
}
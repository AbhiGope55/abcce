#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
    int temp1, temp2, temp3, temp4, temp5, i, winsize = 8, noframes, moreframes;
    char c;
    int reciever(int);
    int simulate(int);
    int nack(int);
    srand(time(0));
    temp4 = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp5 = 0;
    for (i = 0; i < 200; i++)
        rand();
    noframes = rand() / 200;
    printf("\n Number of frames is %d", noframes);
    moreframes = noframes;
    while (moreframes >= 0)
    {
        temp1 = simulate(winsize);
        winsize -= temp1;
        temp4 += temp1;
        if (temp4 > noframes)
            temp4 = noframes;
        for (i = noframes - moreframes; i <= temp4; i++)
            printf("\nSending frame %d", i);
        Sleep(100);
        temp2 = reciever(temp1);
        temp3 += temp2;
        if (temp3 > noframes)
            temp3 = noframes;
        temp2 = nack(temp1);
        temp5 += temp2;
        if (temp5 != 0)
        {
            printf("\n No acknowledgement for the frame %d", temp5);
            Sleep(100);
            for (i = 1; i < temp5; i++)
                ;
            printf("\n Retransmitting frame %d", temp5);
            Sleep(100);
        }
        moreframes -= temp1;
        if (winsize <= 0)
            winsize = 8;
    }
    printf("\n End of sliding window protocol Selective Repect");
    return 0;
}
int reciever(int temp1)
{
    int i;
    for (i = 1; i < 100; i++)
        rand();
    i = rand() % temp1;
    return i;
}
int nack(int temp1)
{
    int i;
    for (i = 1; i < 100; i++)
        rand();
    i = rand() % temp1;
    return i;
}
int simulate(int winsize)
{
    int temp1, i;
    for (i = 1; i < 50; i++)
        temp1 = rand();
    if (temp1 == 0)
        temp1 = simulate(winsize);
    i = temp1 % winsize;
    if (i == 0)
        return winsize;
    else
        return temp1 % winsize;
}
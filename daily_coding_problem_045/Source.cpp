/*

This problem was asked by Two Sigma.

Using a function rand5() that returns an integer from 1 to 5 (inclusive)with uniform probability,
implement a function rand7() that returns an integer from 1 to 7 (inclusive).

//*/


#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int rand5()
{
    return int(((float)((float)(rand() + RAND_MAX - 1) / RAND_MAX)) * 5);
}

int main(int  argc, char ** argv)
{
    int array_5[] = { 0, 0, 0, 0, 0 };
    int array_7[] = { 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < 10000000; i++)
    {
        int idx = rand5();
        array_5[idx]++;
    }

    printf("% 5d, % 5d, % 5d, % 5d, % 5d\n", array_5[0], array_5[1], array_5[2], array_5[3], array_5[4]);

    return 1;
}


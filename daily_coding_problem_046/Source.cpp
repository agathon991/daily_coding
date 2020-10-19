/*

This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.

//*/


#include <stdio.h>
#include <stdlib.h>

int input[] = { -10, -10, 5, 2 };

#define SIZEOF(x)   (sizeof(x)/sizeof(*x))
#define MAX(a,b)    (a>b?a:b)
#define INT_MIN     (-2147483647 - 1)

int main(int argc, char ** argv)
{
    int size = SIZEOF(input);
    int max_val = INT_MIN;

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                max_val = MAX(max_val, input[i] * input[j] * input[k]);
            }
        }
    }
    printf("Max Value (dumbass way): % 5d\n", max_val);

    int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
    int minA = INT_MAX, minB = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (input[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = input[i];
        }
        else if (input[i] > maxB)
        {
            maxC = maxB;
            maxB = input[i];
        }
        else if (input[i] > maxC)
        {
            maxC = input[i];
        }

        if (input[i] < minA)
        {
            minB = minA;
            minA = input[i];
        }
        else if (input[i] < minB)
        {
            minB = input[i];
        }
    }

    int v1 = (maxA * maxB * maxC);
    int v2 = (maxA * minA * minB);

    printf("Max Value (better way): % 5d\n", MAX(v1, v2));

    return 1;
}
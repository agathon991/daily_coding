// daily_coding_problem_2.cpp : Defines the entry point for the console application.
//
// This problem was asked by Uber.
// 
// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
// 
// For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].
// 
// Follow - up: what if you can't use division?

#include "stdafx.h"

#define SIZE(n) (sizeof(n)/sizeof(*n))

// bool numProduct(int * input, int * &output, int numelements)
// {
//     if (input)
//     {
//         if (numelements)
//         {
//             if (output) delete output;
//             output = new int[numelements];
// 
//             if (output)
//             {
//                 int runningProd = 1;
//                 for (int i = 0; i < numelements; i++)
//                 {
//                     output[i] = 1;
//                     for (int j = 0; j < numelements; j++)
//                     {
//                         if (i == j) continue;
//                         output[i] *= input[j];
//                     }
//                 }
//                 return true;
//             }
//         }
//     }
// 
//     return false;
// }

bool numProduct(int * input, int * &output, int numelements)
{
    if (input)
    {
        if (numelements)
        {
            if (output) delete output;
            output = new int[numelements];

            if (output)
            {
                int runningProd = 1;
                
                for (int i = 0; i < numelements; i++)
                {
                    runningProd *= input[i];
                }

                for (int i = 0; i < numelements; i++)
                {
                    output[i] = runningProd / input[i];
                }
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int input[] = {1, 2, 3, 4, 5 };
    int * output = NULL;

    bool retVal = numProduct(input, output, SIZE(input));

    int n = SIZE(input);
    if (n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("% 5d | ", output[i]);
        }
        printf("\n");
    }

    return int(retVal);
}


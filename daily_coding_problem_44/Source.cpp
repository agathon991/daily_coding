/*
This problem was asked by Google.

We can determine how "out of order" an array A is by counting the number of inversions it has.Two elements A[i] and
A[j] form an inversion if A[i] > A[j] but i < j.That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has.Do this faster than O(N ^ 2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions.The array[2, 4, 1, 3, 5] has three inversions : (2, 1), (4, 1), and
(4, 3).The array[5, 4, 3, 2, 1] has ten inversions : every distinct pair forms an inversion.

//*/

#include <stdio.h>
#include <stdlib.h>

#define ceil(x,y)  ((int)(x + (y-1))/y)
#define floor(x,y) ((int)((int)x/(int)y))
#define SIZEOF(x)  (sizeof(x)/sizeof(*x))

int * countAndSort(int * input, int size, int * output, int& inversions)
{
    if (size == 1)
    {
        return input;
    }

    int * l_sorted = countAndSort(input, ceil(size, 2), output, inversions);
    int * r_sorted = countAndSort(input + ceil(size, 2), floor(size, 2), output, inversions);

    int l_elements = ceil(size, 2);
    int r_elements = floor(size, 2);

    for (int i = 0; i < size; i++)
    {
        if (l_elements && r_elements)
        {
            if (*l_sorted <= *r_sorted)
            {
                output[i] = *l_sorted++;
                l_elements--;
            }
            else if (*l_sorted > *r_sorted)
            {
                inversions += l_elements;
                output[i] = *r_sorted++;
                r_elements--;
            }
        }
        else if (r_elements)
        {
            output[i] = *r_sorted++;
            r_elements--;
        }
        else if (l_elements)
        {
            output[i] = *l_sorted++;
            l_elements--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        input[i] = output[i];
    }

    return input;
}

int main(int argc, char ** argv)
{
    int input[] = { 5, 4, 3, 2, 1 };

    int intput_size = SIZEOF(input);
    int num_inversions = 0;
    int inversions = 0;

    int * output = (int*) malloc(sizeof(int) * intput_size);

    for (int i = 0; i < intput_size; i++ )
    {
        for (int j = 0; j < intput_size; j++)
        {
            if ((i < j) && (input[i] > input[j]))
            {
                num_inversions++;
            }
        }
    }

    countAndSort(input, intput_size, output, inversions);

    printf("Brute Force Number of inversions: % 5d", num_inversions);
    printf("Merge Sort Number of inversions: % 5d", inversions);

    free(output);

    return 1;
}


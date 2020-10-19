// This problem was asked by Stripe.
// 
// Given an array of integers, find the first missing positive integer in linear time and constant space.In other words, find the lowest positive integer that does not exist in the array.The array can contain duplicates and negative numbers as well.
// 
// For example, the input[3, 4, -1, 1] should give 2. The input[1, 2, 0] should give 3.
// 
// You can modify the input array in - place.

#define SIZE(x)     (sizeof(x)/sizeof(*x))
#define MAX(a,b)    (((a)>(b))?(a):(b))

// C++ implementation of Radix Sort 
#include<iostream> 
using namespace std;

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp)
{
    int * output = new int[n]; // output array 
    int i, count[10] = { 0 };

    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++)
        count[(MAX(arr[i],0) / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(MAX(arr[i],0) / exp) % 10] - 1] = MAX(arr[i],0);
        count[(MAX(arr[i],0) / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radix_sort(int arr[], int n)
{
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array 
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i && ((i % 5) == 0)) printf("\n");
        printf("% 5d ", arr[i]);
    }
    printf("\n");
}

int find_missing(int input[], int n)
{
    radix_sort(input, n);
    print(input, n);
    int missing = 1;
    int i = 0;
    
    while ((i < n) && (input[i] <= 0)) i++;
    int j = 1;
    for (i; i < n; ++i)
    {
        if ((input[i] - j) > 1)
        {
            missing = j + 1;
            break;
        }
        else
        {
            j = input[i];
        }
    }
    return missing;
}

int main(int argc, char** argv)
{
    int input[] = { -5, 2, 7, 8, 4, 2, 65, 31, 5, 7, 43, 9, 12, 10, 112, 14, 6, 4, 3, 6, 8, 9, 0, 3, 2, 5, 7, 8, 9, 0, 11, 12, 14, 15, 16, 17, 18, 19, 23, 4, -1, 1 };

    int missing_int = find_missing(input, SIZE(input));

    printf("Missing Integer is: %d\n", missing_int);
}

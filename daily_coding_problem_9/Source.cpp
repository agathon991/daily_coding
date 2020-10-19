// This problem was asked by Airbnb.
// 
// Given a list of integers, write a function that returns the largest sum of non - adjacent numbers.Numbers can be 0 or negative.
// 
// For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.[5, 1, 1, 5] should return 10, since we pick 5 and 5.
// 
// Follow - up: Can you do this in O(N) time and constant space ?
// 
// 

#define SIZE(x) (sizeof(x)/sizeof(*x))



int find_max_sum(int * arr, int length)
{
    if (length < 3)
    {
        return 0;
    }

    int val1 = 0;
    int val2 = 0;
    int idx1 = 0;
    int idx2 = 0;

    idx1 = 0;
    idx2 = 2;

    for (int i = 1; i < length; i++)
    {






    }



}

int main(int argc, char** argv)
{
    int arr[] = { 2, 4, 6, 2, 5 };
    int length = SIZE(arr);

    int max_sun = find_max_sum(arr, length);



}
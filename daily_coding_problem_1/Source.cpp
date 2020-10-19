// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
// 
// For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
// 
// Bonus: Can you do this in one pass ?


#include <stdio.h>
#include <string>
#include <vector>

#define SIZE(array) (sizeof(array)/sizeof(*(array)))

static int input[] = { 10, 15, 3, 7 };
static const int target_val = 17;

bool find_matches(int target_value);


int main(int argc, char** argv)
{
    printf("Target Value: %d | Match found: %s\n", target_val, find_matches(target_val)? "True" : "False");
    
    return 1;
}

bool find_matches(int target_value)
{
    for (int i = 0; i < SIZE(input); i++)
    {
        for (int j = 0; i < SIZE(input); j++)
        {
            if (i == j)
            {
                continue;
            }
            if ((input[i] + input[j]) == target_val)
            {
                return true;
            }
        }
    }
    return false;
}




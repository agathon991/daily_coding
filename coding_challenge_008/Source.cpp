#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include <string>
#include <vector>

/*

Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer
range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0

*/


using namespace std;

class solution {
public:

    /*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.*/
    int reverse(int x)
    {
        int64_t output = 0;

        while (x)
        {
            output = (output * 10) + (x % 10);
            x = x / 10;
        }

        if (output < INT_MIN) return 0;
        if (output > INT_MAX) return 0;

        return (int)output;
    }
};

int main(int argc, char* argv[])
{
    solution x;
    vector<int> inputs = { 1534236469, 123, -123, 120, 0 };
    vector<int> answers = { 0, 321, -321, 21, 0 };

    for (int i = 0; i < inputs.size(); i++)
    {
        int s = x.reverse(inputs.at(i));

        printf("Input: %25d | output %25d | %s\n",
            inputs.at(i), s, s == answers.at(i) ? "PASSED" : "FAILED");

    }

    return 0; // all is well that ends well!
}

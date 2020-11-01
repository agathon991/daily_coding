#define _CRT_SECURE_NO_WARNINGS

/*

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect 
on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because 
either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.


Example 1:

Input: str = "42"
Output: 42
Example 2:

Input: str = "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: str = "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: str = "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: str = "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. There fore INT_MIN (−231) is returned.

*/

#include "stdio.h"
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        // pretty naive implementation but it works...
        // and doesn't create too many intermediate vars

        const char* c = s.c_str();

        int value = 0;
        int idx = 0;
        bool can_assign_sign = true;
        bool neg_sign_assigned = false;
        bool parsing_leading_white_space = true;
        int max_val = INT_MAX / 10;
        int min_val = INT_MIN / 10;

        while (c[idx])
        {
            if (parsing_leading_white_space && c[idx] == ' ')
            {
                idx++;
                continue;
            }

            parsing_leading_white_space = false;

            if (c[idx] == '-')
            {
                if (can_assign_sign)
                {
                    can_assign_sign = false;
                    neg_sign_assigned = true;
                }
                else
                {
                    break;
                }
            }
            else if (c[idx] == '+')
            {
                if (can_assign_sign)
                {
                    can_assign_sign = false;
                    neg_sign_assigned = false;
                }
                else
                {
                    break;
                }
            }
            else if ((c[idx] >= '0') && c[idx] <= '9')
            {
                bool overflow = false;
                can_assign_sign = false;

                if (neg_sign_assigned)
                {
                    overflow = (value < min_val);
                }
                else
                {
                    overflow = (value > max_val);
                }

                if (!overflow)
                {
                    value = value * 10;
                }

                if (!overflow && neg_sign_assigned)
                {
                    overflow = (value <= (INT_MIN + (c[idx] - '0')));
                    if (!overflow)
                    {
                        value -= (c[idx] - '0');
                    }
                }
                else if (!overflow)
                {
                    overflow = (value >= (INT_MAX - (c[idx] - '0')));
                    if (!overflow)
                    {
                        value += (c[idx] - '0');
                    }
                }

                if (overflow)
                {
                    value = neg_sign_assigned ? INT_MIN : INT_MAX;
                    break;
                }
            }
            else
            {
                // some other alphabet or symbol found
                // stop conversion and return what we have
                break;
            }

            idx++;
        }

        return (int)value;
    }
};



int main(int argc, char* argv[])
{

    Solution x;
    vector<string> inputs{ "2147483648", "2147483647", "2147483646", "42", "20000000000000000000", "words and 987", "   -42", "4193 with words", "-91283472332" };
    vector<int> answers{ 2147483647, 2147483647, 2147483646, 42, INT_MAX, 0, -42, 4193, -2147483648 };

    for (int i = 0; i < inputs.size(); i++)
    {
        int ans = x.myAtoi(inputs.at(i));
        printf("%25s evaluates to %10d, %10s\n", inputs.at(i).c_str(), ans, ans == answers.at(i) ? "Passed" : "Failed");
    }




    return 0; // all is well that ends well!
}


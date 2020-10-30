#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include <string>
#include <vector>

/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

*/

using namespace std;

class solution {
public:
    string longestPalindrome(string s)
    {
        const char* c = s.c_str();
        const int len = (int)s.length();

        int start = 0;
        int end = 0;

        int longest_start = 0;
        int longest_end = 0;
        int longest_length = 0;

        if (len == 0) return "";
        if (len == 1) return s;
        if (len == 2) return ((c[0] == c[1]) ? s : (s.substr(0, 1)));

        for (int start = 0; start < len; start++)
        {
            for (int end = len; end > start + longest_length; end--)
            {
                bool is_pali = true;
                bool is_odd = ((end + start) & 1) ? true : false;

                int center = start + (end - start) / 2;
                
                int x = 1;
                while (((center - x) >= start) && is_pali)
                {
                    if (c[center - x] != c[center + x + (is_odd ? 0 : -1)])
                    {
                        is_pali = false;
                    }
                    x++;
                }

                if ((is_pali) && ((end - start) + 1 >= longest_length))
                {
                    longest_length = end - start;
                    longest_start = start;
                    longest_end = end;
                    break;
                }
            }
        }
        if (longest_length)
        {
            return (s.substr(longest_start, longest_length));
        }
        else
        {
            return "";
        }
    }
};

int main(int argc, char* argv[])
{
    solution x;
    vector<string> inputs = { "amanaplanacanalpanama", "racecar", "babad", "cbbd", "a", "ac", "", "abc", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };

    for (auto s : inputs)
    {
        printf("Longest palindrome for %s is %s.\n", s.c_str(), x.longestPalindrome(s).c_str());
    }

    return 0; // all is well that ends well!
}


#define _CRT_SECURE_NO_WARNINGS

/*
Longest Substring Without Repeating Characters

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Input: s = ""
Output: 0
*/

#include "stdio.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest_substr = 0;
        const int len = (int)s.length();
        int i, j;

        if (len == 1)
        {
            return 1;
        }

        const char* c = s.c_str();

        for (i = 0; i < len - 1; i++)
        {
            int substr_start = i;
            char abc[256] = { 0 };
            abc[c[i]]++;

            for (j = i + 1; j < len; j++)
            {
                if (!abc[c[j]])
                {
                    abc[c[j]]++;
                }
                else
                {
                    break;
                }
            }
            // previously used letter encountered
            longest_substr = longest_substr > (j - i) ? longest_substr : (j - i);
        }
        return longest_substr;
    }
};

int main(int argc, char* argv[])
{
    Solution x;
    vector<string> s = { "pwwkew", "au", " ", "abcabcbb", "bbbbb", "" };
    vector <uint32_t> ans = { 3, 2, 1, 3, 1, 0 };

    for (uint32_t i = 0; i < s.size(); i++)
    {
        int answer = x.lengthOfLongestSubstring(s.at(i));
        printf("%s returns %d, expecting %d\n", s.at(i).c_str(), answer, ans.at(i));
    }

    return 0; // all is well that ends well!
}

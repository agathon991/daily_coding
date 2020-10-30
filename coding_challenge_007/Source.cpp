#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include <string>
#include <vector>

/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/


using namespace std;

class solution {
public:

    /*Runtime: 4 ms, faster than 99.53% of C++ online submissions for ZigZag Conversion.*/
    string convert(string s, int numRows)
    {
        string output;
        int len;
        int idx;
        int rows_above, rows_below;
        const char* c = s.c_str();

        // row 1
        len = (int)s.length();
        idx = 0;
        if (numRows <= 1)
        {
            return s;
        }

        for (int row = 0; row < numRows; row++)
        {
            rows_above = row;
            rows_below = numRows - (row + 1);
            idx = row;

            while (idx < len)
            {
                if (rows_below && (idx < len))
                {
                    output += c[idx];
                    idx += (rows_below + (rows_below - 1)) + 1;
                }

                if (rows_above && (idx < len))
                {
                    output += c[idx];
                    idx += (rows_above + (rows_above - 1)) + 1;
                }
            }
        }
        return output;
    }
};

int main(int argc, char* argv[])
{
    solution x;
    vector<string> inputs = { "PAYPALISHIRING" , "PAYPALISHIRING", "PAHNAPLSIIGYIR", "A", "PAYPALISHIRING" };
    vector<int> input_rows = { 4, 3, 3, 1, 4 };
    vector<string> answers = { "PINALSIGYAHRPI", "PAHNAPLSIIGYIR", "PAIIANPSIYRHLG", "A" , "PINALSIGYAHRPI" };

    for (int i = 0; i < inputs.size(); i++)
    {
        string s = x.convert(inputs.at(i), input_rows.at(i));

        printf("Input: %25s | Rows: %5d | output %25s | %s\n",
            inputs.at(i).c_str(), input_rows.at(i), s.c_str(), s == answers.at(i) ? "PASSED" : "FAILED");

    }

    return 0; // all is well that ends well!
}

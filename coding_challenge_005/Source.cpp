#define _CRT_SECURE_NO_WARNINGS

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Input: nums1 = [2], nums2 = []
Output: 2.00000

*/

#include "stdio.h"
#include <string>
#include <vector>

using namespace std;

class solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> combined;

        double ret = 0.0;
        int idx1 = 0;
        int idx2 = 0;

        while (idx1 < nums1.size() || idx2 < nums2.size())
        {
            int v1 = idx1 < nums1.size() ? nums1.at(idx1) : 1 << 30;
            int v2 = idx2 < nums2.size() ? nums2.at(idx2) : 1 << 30;
            int v;

            if (v1 < v2)
            {
                idx1++;
                v = v1;
            }
            else
            {
                idx2++;
                v = v2;
            }
            combined.push_back(v);
        }

        if (combined.size())
        {
            if (combined.size() % 2 == 0)
            {
                ret = ((double)combined.at(combined.size() / 2) + (double)combined.at((combined.size() / 2) - 1)) / 2;
            }
            else
            {
                ret = (double)combined.at((combined.size() / 2));
            }
        }

        return ret;
    }

    double findMedianSortedArrays_NoIntermediateVec(vector<int>& nums1, vector<int>& nums2)
    {
        // we can use the fact that the input arrays are sorted and not
        // go on to create a "combined" array

        int s1 = 0;
        int s2 = 0;

        int nums_remaining = (int)(nums1.size() + nums2.size());
        const int median_numbs = (nums_remaining / 2) + 1;
        const bool is_odd = (nums1.size() + nums2.size()) & 1;

        while (nums_remaining > median_numbs)
        {
            int v1 = (s1 < nums1.size()) ? nums1.at(s1) : 1 << 30;
            int v2 = (s2 < nums2.size()) ? nums2.at(s2) : 1 << 30;

            if (v1 < v2)
            {
                s1++;
            }
            else
            {
                s2++;
            }
            nums_remaining--;
        }

        if (is_odd)
        {
            int val = 0;
            int v1 = (s1 < nums1.size()) ? nums1.at(s1) : 1 << 30;
            int v2 = (s2 < nums2.size()) ? nums2.at(s2) : 1 << 30;
            val = v1 < v2 ? v1 : v2;
            return (double)val;
        }
        else
        {
            int val = 0;
            int v1 = (s1 < nums1.size()) ? nums1.at(s1) : 1 << 30;
            int v2 = (s2 < nums2.size()) ? nums2.at(s2) : 1 << 30;
            val = v1 < v2 ? v1 : v2;
            v1 < v2 ? s1++ : s2++;

            v1 = (s1 < nums1.size()) ? nums1.at(s1) : 1 << 30;
            v2 = (s2 < nums2.size()) ? nums2.at(s2) : 1 << 30;
            val += (v1 < v2 ? v1 : v2);
            return (double)val / 2;
        }
    }
};


int main(int argc, char* argv[])
{
    solution x;
    vector<vector<int>> v1s = { {}, {1,3}, {1,2}, {0,0}, {}, {2} };
    vector<vector<int>> v2s = { {2, 3}, {2}, {3,4}, {0,0}, {1}, {} };
    vector <double> ans = { 2.50000, 2.00000, 2.50000, 0.00000, 1.00000, 2.00000 };

    for (uint32_t i = 0; i < v1s.size(); i++)
    {
        printf("expected: %2.6f, received: %2.6f\n", ans.at(i), x.findMedianSortedArrays(v1s.at(i), v2s.at(i)));
    }

    for (uint32_t i = 0; i < v1s.size(); i++)
    {
        printf("No Vec: expected: %2.6f, received: %2.6f\n", ans.at(i), x.findMedianSortedArrays_NoIntermediateVec(v1s.at(i), v2s.at(i)));
    }

    return 0; // all is well that ends well!
}

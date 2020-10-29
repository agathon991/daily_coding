#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
/*

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry_forward = 0;
        ListNode* node = new ListNode;
        ListNode* parent = node;

        while (l1 || l2 || carry_forward)
        {
            int sum_value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry_forward;
            carry_forward = sum_value / 10;
            sum_value %= 10;

            node->val = sum_value;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            if ((l1) || (l2) || (carry_forward != 0))
            {
                node->next = new ListNode;
                node = node->next;
            }
        }

        return parent;
    }
};

int main(int argc, char* argv[])
{
    Solution x;

    ListNode l1(9, &ListNode(9, &ListNode(9, &ListNode(9, &ListNode(9, &ListNode(9, &ListNode(9, &ListNode(9))))))));
    ListNode l2(9, &ListNode(9, &ListNode(9, &ListNode(9))));
    ListNode* y = x.addTwoNumbers(&l1, &l2);

    while (y)
    {
        printf("%d ", y->val);

        ListNode* z = y->next;
        delete y;
        y = z;
    }

    return 0; // all is well that ends well!
}


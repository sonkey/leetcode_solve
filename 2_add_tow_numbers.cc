/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1;
        ListNode *tail = nullptr;
        int a = 0, b = 0;
        while (l1 && l2) {
            a = (l1->val + l2->val + b) % 10;
            b = (l1->val + l2->val + b) / 10;
            l1->val = a;
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2 == nullptr && l1) {
            while (l1) {
                a = (l1->val + b) % 10;
                b = (l1->val + b) / 10;
                l1->val = a;
                tail = l1;
                l1 = l1->next;
            }
        } else if (l1 == nullptr && l2) {
            tail->next = l2;
            l1 = tail->next;
            while (l1) {
                a = (l1->val + b) % 10;
                b = (l1->val + b) / 10;
                l1->val = a;
                tail = l1;
                l1 = l1->next;
            }
        } 

        if (b != 0) {
            ListNode *node = new ListNode(b);
            tail->next = node;
        }

        return head; 
    }
};
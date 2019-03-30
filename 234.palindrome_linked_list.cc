/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half = reverse(slow);

        while (head != NULL && half != NULL) {
            if (head->val != half->val) return false;
            head = head->next;
            half = half->next;
        }

        return true;
    }

private:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* pre = head;
        ListNode* cur = pre->next;
        pre->next = NULL;

        ListNode* tmp = reverse(cur);
        cur->next = pre;

        return tmp;
    }
};

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* pre = head;
        ListNode* cur = pre->next;
        ListNode* tmp = reverseList(cur);
        cur->next = pre;
        pre->next = NULL;

        return tmp; 
    }
};

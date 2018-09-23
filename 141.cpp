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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;

        while (slow != fast) {
            if (slow == NULL || fast == NULL) return false;
            if (slow->next) slow = slow->next;
            else return false;
            if (fast->next && fast->next->next)
                fast = fast->next->next;
            else return false;
        }

        return true;
    }
};

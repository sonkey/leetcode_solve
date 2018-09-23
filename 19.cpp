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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dumb(0);
        dumb.next = head;

        ListNode* first = &dumb;
        while (n--) {
            first = first->next;
        }
        first = first->next;

        ListNode* second = &dumb;
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        ListNode* tmp = second->next;
        second->next = tmp->next;
        return dumb.next;
    }
};

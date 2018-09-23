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

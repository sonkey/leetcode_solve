// https://leetcode-cn.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto list: lists) {
            if (list) pq.push(list);
        }

        ListNode tmp(0);
        ListNode *head = &tmp;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            head->next = node;
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
            head = node;
        }

        head = tmp.next;
        return head;
    }
};
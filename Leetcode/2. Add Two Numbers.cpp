/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int k = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (l1 || l2) {
            ListNode* next = new ListNode();
            cur->next = next;
            cur = cur->next;
            if (l1 && l2) {
                cur->val = (l1->val + l2->val + k) % 10;
                k = (l1->val + l2->val + k) / 10;
                l1 = l1->next, l2 = l2->next;
            } else 
                if (l1) {
                    cur->val = (l1->val + k) % 10;
                    k = (l1->val + k) / 10;
                    l1 = l1->next;
                } else {
                    cur->val = (l2->val + k) % 10;
                    k = (l2->val + k) / 10;
                    l2 = l2->next;
                }
        }
        if (k != 0)
            cur->next = new ListNode(k);
        return dummy->next;
    }
};

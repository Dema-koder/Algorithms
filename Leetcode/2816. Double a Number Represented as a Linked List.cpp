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
    int p = 0;

    void f(ListNode* cur) {
        if (!cur)
            return;
        f(cur->next);
        int x = cur->val * 2 + p;
        p = x / 10;
        cur->val = x % 10;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        f(dummy);
        if (dummy->val == 0)
            return dummy->next;
        return dummy;
    }
};

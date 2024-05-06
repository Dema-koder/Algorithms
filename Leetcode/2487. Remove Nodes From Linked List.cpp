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
    int mx = 0;
    ListNode* f(ListNode* cur, ListNode* p) {
        if (!cur->next) {
            mx = max(mx, cur->val);
            return cur;
        }
        auto prev = f(cur->next, cur);
        if (cur->val < mx) {
            mx = max(mx, cur->val);
            cur->next = prev;
            return prev;
        }
        else {
            cur->next = prev;
            mx = max(mx, cur->val);
            return cur;
        }
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        f(dummy, head);
        return dummy->next;
    }
};

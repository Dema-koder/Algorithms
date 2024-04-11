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
    int k = 0, index;
    void f(ListNode* head, int ind) {
        if (!head) {
            k = ind - 1;
            return;
        }
        f(head->next, ind + 1);
        if (ind == k - index)
            head->next = head->next->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        index = n;
        f(head, 1);
        if (k == n)
            return head->next;
        return head;
    }
};

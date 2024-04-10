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
    ListNode* start;
    int k = 0;

    void f(ListNode* cur, int ind) {
        if (!cur) {
            return;
        }
        k++;
        f(cur->next, ind + 1);
        if (ind > k / 2) {
            ListNode* tmp = start->next;
            cur->next = tmp;
            start->next = cur;
            start = tmp;
        } else 
            if (ind == k / 2) 
                cur->next = nullptr;
    }

    void reorderList(ListNode* head) {
        start = head;
        f(head, 0);
    }
};

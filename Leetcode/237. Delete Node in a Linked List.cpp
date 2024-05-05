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
    void deleteNode(ListNode* node) {
        while (true) {
            ListNode* next = node->next;
            if (!next->next) {
                node->val = next->val;
                next = nullptr;
                node->next = next;
                return;
            }
            node->val = next->val;
            node = next;
        }
    }
};

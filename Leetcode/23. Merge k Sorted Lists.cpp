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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        ListNode* dummy = new ListNode();
        while (lists.size() > 1) {
            int l = 0, r = 1;
            while (true) {
                ListNode* cur = dummy;
                dummy->next = nullptr;
                while (lists[l] || lists[r]) {
                    if (!lists[l]) {
                        while (lists[r])
                            cur->next = lists[r], cur = cur->next, lists[r] = lists[r]->next;
                        break;
                    }
                    if (!lists[r]) {
                        while (lists[l])
                            cur->next = lists[l], cur = cur->next, lists[l] = lists[l]->next;
                        break;
                    }
                    if (lists[l]->val < lists[r]->val)
                        cur->next = lists[l], cur = cur->next, lists[l] = lists[l]->next;
                    else 
                        cur->next = lists[r], cur = cur->next, lists[r] = lists[r]->next;
                }
                lists[r / 2] = dummy->next;
                if (r == lists.size() - 1) {
                    lists.resize((r + 2) / 2);
                    break;
                }
                r += 2, l += 2;
                if (l == lists.size()) {
                    lists.resize(l / 2);
                    break;
                }
                if (r == lists.size()) 
                    l = 0, r--;
            }
        }
        return dummy->next;
    }
};

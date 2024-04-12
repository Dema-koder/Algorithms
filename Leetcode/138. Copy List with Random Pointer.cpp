/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;

    void f(Node* v) {
        if (!v)
            return;
        Node* cur = new Node(v->val);
        mp[v] = cur;
        f(v->next);
    }

    Node* copyRandomList(Node* head) {
        f(head);
        for (auto to: mp) {
            Node* cur = to.second;
            if (cur != nullptr) {
                cur->next = mp[to.first->next];
                cur->random = mp[to.first->random];
            }
        }
        return mp[head];
    }
};

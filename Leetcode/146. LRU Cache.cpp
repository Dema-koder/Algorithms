class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node() {
    }

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int n;
    unordered_map<int, Node*>mp;
    Node* dummy = new Node();
    Node* last = dummy;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            Node* prev = cur->prev;
            Node* next = cur->next;
            if (next != nullptr) {
                prev->next = next;
                next->prev = prev;
                last->next = cur;
                cur->prev = last;
                cur->next = nullptr;
                last = cur;
            }
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        cout << "put\n";
        if (mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            Node* prev = cur->prev;
            Node* next = cur->next;
            if (next != nullptr) {
                prev->next = next;
                next->prev = prev;
                last->next = cur;
                cur->prev = last;
                cur->next = nullptr;
                last = cur;
            }
            cur->val = value;
        } else {
            if (mp.size() < n) {
                Node* cur = new Node(key, value);
                last->next = cur;
                cur->prev = last;
                last = cur;
                mp[key] = cur;
            } else {
                Node* first = dummy->next;
                dummy->next = first->next;
                if (first->next != nullptr)
                    first->next->prev = dummy;
                mp.erase(first->key);
                if (first == last)
                    last = dummy;
                Node* cur = new Node(key, value);
                last->next = cur;
                cur->prev = last;
                last = cur;
                mp[key] = cur;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

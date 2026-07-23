//146. LRU Cache
//Compiler : C++
//https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    struct Doublist{
        int val;
        Doublist* prev = NULL;
        Doublist* next = NULL;
        Doublist(int x) {
            val = x;
        }
    };
    Doublist* head = NULL;
    Doublist* tail = NULL;
    unordered_map<int, int> cache;
    unordered_map<int, Doublist*> add;

    int c = 0;

    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(cache.count(key) == false) return -1;
        add_to_list(key, head, tail);
        return cache[key];
    }

    void add_to_list(int x, Doublist*& head, Doublist*& tail) {
        if(head == NULL && tail == NULL) {
            head = new Doublist(x);
            tail = head;
            add[x] = head;
            return;
        }
        else if(add.count(x))  {                 //reaccessing same key
            Doublist* curr  = add[x];
            Doublist* left = curr->prev;
            Doublist* right = curr->next;
            if(right == NULL) return;      //last accessed element accesses again
            else if(left == NULL) {        //1st accessed one
                head = right;
                head->prev = NULL;
            }
            else {                          //remaining cases (sandwitched)
                left->next = right;
                right->prev = left;
            }
            curr->next = NULL;
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }                        
        else if(add.size() == c) {           //capacity full
            add.erase(head->val);
            cache.erase(head->val);
            tail->next = new Doublist(x);
            tail->next->prev = tail;
            tail = tail->next;
            head = head->next;
            head->prev = NULL;
            add[x] = tail;
        }
        else {
            tail->next = new Doublist(x);
            tail->next->prev = tail;
            tail = tail->next;
            add[x] = tail;
        }
    }
    
    void put(int key, int value) {
        add_to_list(key, head, tail);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
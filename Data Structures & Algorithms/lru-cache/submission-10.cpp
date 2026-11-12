class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    // left points to the least used cache
    Node* left;
    // right points to most recently used cache
    Node* right;

    // removal operation
    void remove(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
    }

    // insert in the end
    void insert(Node* node) {
        Node* before = right->prev;
        before->next = node;
        node->prev = before;
        right->prev = node;
        node->next = right;

    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        // left and right point to dummy nodes
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        // find if key is already in the cache
        if (cache.find(key) != cache.end()) {
            // get the node
            Node* node = cache[key];
            // remove first
            remove(node);
            // then insert at the end
            insert(node);
            return node->value;
        }
        // return -1 if key is not in the cache
        return -1;
    }
    
    void put(int key, int value) {
        // if key is already in the cache -> remove
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        // creat a node for the key
        Node* newNode = new Node(key, value);
        // insert the newNode into the cache
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* removeLRU = left->next;
            remove(removeLRU);
            cache.erase(removeLRU->key);
            delete removeLRU;
        }
    }
};

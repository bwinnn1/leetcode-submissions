class MyCircularQueue {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int v, ListNode* ne = nullptr, ListNode* p = nullptr) : val(v), next(ne), prev(p) {}
    };

    int capacity;
    ListNode* left;
    ListNode* right;
public:
    MyCircularQueue(int k) {
        capacity = k;
        left = new ListNode(0);
        right = new ListNode(0, nullptr, left);
        left->next = right;
    }
    
    bool enQueue(int value) {
        if (isFull()) {return false;}
        ListNode* curr = new ListNode(value, right, left);
        right->prev->next = curr;
        right->prev = curr;
        capacity--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {return false;}
        ListNode* tmp = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete tmp;
        capacity++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return left->next->val;
    }
    
    int Rear() {
        if (isEmpty()) {return -1;}
        return right->prev->val;
    }
    
    bool isEmpty() {
        if (left->next == right){return true;}
        return false;
    }
    
    bool isFull() { 
        return capacity ==0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
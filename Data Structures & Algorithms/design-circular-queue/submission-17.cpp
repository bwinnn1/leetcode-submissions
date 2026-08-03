class MyCircularQueue {
    //initialize the queue
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int v, ListNode* ne = nullptr, ListNode* pr = nullptr) : val(v), next(ne), prev(pr) {}
    };

    int capacity;
    int currentSize;
    ListNode* left;
    ListNode* right;
public:
    MyCircularQueue(int k) {
        capacity = k;
        currentSize = 0;
        left = new ListNode(0);
        right = new ListNode(0, nullptr, left);
        //after you have the right node, you can point left->next to the right
        left->next = right;
    }
    
    bool enQueue(int value) {
        if (isFull()) {return false;}

        ListNode* curr = new ListNode(value, right, right->prev);
        right->prev->next = curr;
        right->prev = curr;
        currentSize++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {return false;}

        ListNode* toRemove = left->next;

        left->next = toRemove->next;
        toRemove->next->prev = left;
        delete toRemove;
        currentSize--;
        
        return true;
    }
    
    int Front() {
        if (isEmpty()) {return -1;}

        return left->next->val;
    }
    
    int Rear() {
        if (isEmpty()) {return -1;}
        return right->prev->val;
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == capacity;
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
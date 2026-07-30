class MyCircularQueue {
private:
    vector<int> q;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if (q.size() == size){
            return false;
        }
        q.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(q.size()==0) {
            return false;
        }
        q.erase(q.begin());
        return true;
    }
    
    int Front() {
        if (q.empty()) {return -1;}
        else{
            return q.front();
        }
    }
    
    int Rear() {
        if (q.empty()){return -1;}
        else {
            return q.back();
        }
    }
    
    bool isEmpty() {
        if (q.size() == 0 ){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        return q.size() == size;
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
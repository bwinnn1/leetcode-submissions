class MinStack {
private:
    struct Node {
        int val;
        int minSoFar;
    };
public:
    stack<Node> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        int minSoFar = 0;
        if (stk.empty()) {
            minSoFar = val;
        } else {
            minSoFar = min(val, stk.top().minSoFar);
        }
        
        stk.push(Node{val, minSoFar});
    }
    
    void pop() {
        if (stk.empty()) {
            return;
        }
        stk.pop();
    }
    
    int top() {
        if (stk.empty()) {
            return -1;
        }
        return stk.top().val;
    }
    
    int getMin() {
        return stk.top().minSoFar;
    }
};

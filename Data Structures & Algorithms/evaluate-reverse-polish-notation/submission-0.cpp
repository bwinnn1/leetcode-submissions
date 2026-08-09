class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> stk;

        for (const string& c : tokens) {
            // use const string& because we don't need to modify just access
            if (c == "+"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a+b);
            } else if (c == "-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b - a);
            } else if (c == "*") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b * a);
            } else if (c == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b / a);
            } else {
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};

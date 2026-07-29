class Solution {
public:
    int calculate(string s) {
        //need a way to convert string into expression
        //numbers can be converted into integers
        //math expressions like /, +, -, etc

        //remove all the spaces
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int result = 0;

        vector<int> stack;
        int num = 0;
        //operation default is +
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if (!isdigit(c) || i == s.size()-1){
                if (op == '+') {
                    stack.push_back(num);
                } else if (op == '-') {
                    stack.push_back(-num);
                } else if (op == '*') {
                    int prev = stack.back();
                    stack.pop_back();
                    stack.push_back(prev*num);
                } else {
                    int prev = stack.back();
                    stack.pop_back();
                    stack.push_back(prev/num);
                }
                op = c;
                num = 0;
            }
        }

        //now stack only has numbers (3,4,5)
        for (int x : stack) {
            result += x;
        }
        return result;
    }
};
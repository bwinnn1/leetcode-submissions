class Solution {
   public:
    int minOperations(string s) {
        int counter = 0;  // counter to check how many operations
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    counter++;
                }
            } else {
                if (s[i] == '1') {
                    counter++;
                }
            }
        }
        return min(counter, (int)s.size() - counter);
    }        
};
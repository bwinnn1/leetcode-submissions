class Solution {
public:
    int firstUniqChar(string s) {
        // iterate through the array once -> collect all the character -> which one does not
        // using hash table to collect the count of each char

        unordered_map<int, int> count;

        // increase the count of each character in s
        for (char c : s) {
            count[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
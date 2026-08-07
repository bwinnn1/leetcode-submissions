class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //use set to look up characters
        unordered_set<char> charSet;

        int result = 0;
        int left = 0;
        for (int r = 0; r < s.size(); r++) {
            // .end() return true if a character is not in the set
            while (charSet.find(s[r]) != charSet.end()) { 
                // use while loop in case have to remove multiple chars in a row
                // read as if s[r] is in the charSet
                // remove the character at the left pointer
                // then increase by 1
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[r]);
            result = max(result, r - left + 1);
        }

        return result;
    }
};

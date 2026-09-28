class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

        int left = 0;
        int res = 0;

        for (int right = 0; right < s.size(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                // if s[right] already exists in the set
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};

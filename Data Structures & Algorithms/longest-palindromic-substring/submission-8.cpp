class Solution {
public:
    string longestPalindrome(string s) {
        int longestSubtring = 0;
        int startPal = 0;

        for (int i = 0; i < s.size(); i++) {
            // odd length
            // ababd
            // both start at i
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longestSubtring) {
                   startPal = l;
                    longestSubtring = r - l + 1; 
                }

                // expand outward
                l--;
                r++;
            }

            // even length
            // check even length when odd length fails 
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longestSubtring) {
                   startPal = l;
                    longestSubtring = r - l + 1; 
                }
                l--;
                r++;
            }
        }
        return s.substr(startPal, longestSubtring);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        // why these variables:
        // need to know where does the palindrome starts and where it ends
        int longestPal = 0, startPal = 0;
    
        for (int i = 0; i < s.size(); i++) {
            // odd length 
            // both pointers start at the same index

            int l = i, r = i;
            // left limit is 0 bababa
            // check both if not then false -> not palidrome
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                // if true
                // check to see the current length is larger than longest one we have
                if (r - l + 1 > longestPal) {
                    startPal = l;
                    longestPal = r - l + 1;
                }
                //update the position -> expand outward
                l--;
                r++;
            }

            // if odd length fails then check for even length by moving r by 1
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                // if true then check for length
                if (r - l + 1 > longestPal) {
                    startPal = l;
                    longestPal = r - l + 1;
                }

                // update the position
                l--;
                r++;
            }
        }


        // return the longest palindrom by using substring
        return s.substr(startPal, longestPal);
    }
};

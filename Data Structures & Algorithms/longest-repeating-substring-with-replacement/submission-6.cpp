class Solution {
public:
    int characterReplacement(string s, int k) {
        // make a hashtable to count the occurrence of chars
        unordered_map<char, int> count;
        
        int result = 0; // result to print 
        int left = 0; // left pointer
        int r = 0; // right moving pointer

        int maxFrequency = 0;
        for (r = 0; r < (int)s.size(); r++) {
            // at every index increase the count of that char by one
            count[s[r]]++;

            // find the current max frequency
            // example: "AAABABB"
            // index = 0. "A" => A : 1
            // index = 1. "A" => A : 2
            // index = 3. "B" => A : 3 B : 1

            maxFrequency = max(maxFrequency, count[s[r]]);
            
            int windowSize = r - left + 1;
            while (windowSize - maxFrequency > k) {
                // if in the current window . there are more left over than that we
                count[s[left]]--; // decrease the count for the character on the left since we moving on

                // shrinking the window size by move the left pointer
                left++;
                windowSize = r - left + 1;
            }

            // update the result at each iteration . between the current result and the curent window size . whichever is bigger
            result = max(result, r - left + 1);
        }

        return result;
    }
};

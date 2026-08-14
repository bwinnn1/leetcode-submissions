class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // make a hashtable to count to occurrence of the chars in s1

        // iterate through the string in sliding window if window has a char that is in hashtable decrease that chars in hashtable by one

        if (s1.size() > s2.size()) return false;
            
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // only count the characters within the size of s1
        // if s1 = "ab" s2 = "eidbaooo" 
        // 110000000000000 s2count = 00001000001000

        // if we do i < 26 - > everything would be one -> so it doesn't make sense
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // find all the matches the final number
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            } 
        }

        // left pointer for sliding window

        int left = 0;

        // we start at s1.length since we already check that in the first loop
        for (int r = s1.length(); r < s2.length(); r++) {
            // base case to check for true because if matches == 26 means all of the 
            // characters match
            if (matches == 26) {
                return true;
            }

            // if not for the condition above
            // new right char will be added to move on
            int index = s2[r] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                // this condition is because we might increase s2Count at index more than s1Count at index by one which then result in this condition true
                // example: s1Count[3] = 1 / s2Count[3] = 2 -> if s1Count[3] = 2 means it equals to s2Count[3] = 2
                matches--;
            }

            index = s2[left] - 'a';
            s2Count[index]--;
            // somehow by decrement the left char but s2Count at index equals s1Count at index then increases matches by one
            // if s1 a : 0 and b : 1 
            // when decrement s2, a : 1 -> 0, b : 1, c : 0, etc . mean matching at index a which is at the left pointer 
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] - 1 == s2Count[index]){
                // if we somehow decrement s2Count at index to be less than s1Count at index by one . it means they lost one matching index values
                matches--;
            }
            left++;
        }
        // return true if matches == 26 in the end
        return matches == 26;
    }
};

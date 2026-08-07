class Solution {
public:
    int characterReplacement(string s, int k) {
        // use set to keep track of what's in the window
        unordered_map<char, int> count;

        int result = 0;
        int left = 0;
        // maxfrequency represents the size of the most common letter in the window
        int maxfrequency = 0;
        for (int r = 0; r < s.size(); r++){
            count[s[r]]++;
            maxfrequency = max(maxfrequency, count[s[r]]);
            // compare the current max frequency with the frequnecy of the letter at s[r]. pick whichever is higher = the most common one

            while ((r - left + 1) - maxfrequency > k) {
                // left over characters
                // If I keep the most common letter as-is, how many other characters are sitting in this window that don't match it
                count[s[left]]--; //decrease the size first before move left because if the next left char is different. we would accidently reduce the count of a different letter
                left++;
            }

            result = max(result, r - left + 1);
        }
        return result;
    }
};

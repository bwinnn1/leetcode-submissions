class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        // why: starting at i = 1 since we are checking it with the current prefix
        for (int i = 1; i < strs.size(); i++) {

            // start at the first char of each string
            int j = 0;
            while (j < min(prefix.length(), strs[i].length())) {
                // check current prefix char at j to string at j + 1
                if (prefix[j] != strs[i][j]) {
                    break;
                }
                // if condition fails then increase j to check the next
                j++;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};
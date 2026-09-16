class Solution {
public:
    int minDistance(string word1, string word2) {
        // goals:
            // make word1 == word2 
            // by doing n times of operations
            // each operation increases count by 1

        // edge cases:
            // word1 will always be word2 by doing n operations
        
        // pseudocode:
            // iterate through word2
            // record each word through a map and its position

            // then -> iterate through word1
            // compare each index of word1 to word2
            // make apt changes (replace, remove, insert) then compare them 
            // dynamic programming

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        // fill it left to right and top to bottom starting at pos 1
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // last char so inherit the answer for previous
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        
        return dp[m][n];
    }
};

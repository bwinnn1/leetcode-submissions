class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // similar to the daily temp question
        int n = nums.size();
        // result vector to store 
        vector<int> LIS(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        return *max_element(LIS.begin(), LIS.end());
    }
};

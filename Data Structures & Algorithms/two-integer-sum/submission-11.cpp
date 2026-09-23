class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make a result output to store the original indices
        vector<pair<int, int>> result;
        
        for (int i = 0; i < nums.size(); i++) {
            result.push_back({nums[i], i});
        }

        sort(result.begin(), result.end());

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = result[i].first + result[j].first;

            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return {min(result[i].second, result[j].second), max(result[i].second, result[j].second)};
            }
        }
        return {};
    }
};

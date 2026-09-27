class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // result vector to store results :3
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // -1 0 1 2 -1 -4
        // -4 -1 -1 0 1 2
        // ends at n - 2 because right starts at n - 1 already
        for (int i = 0; i < n - 2; i++) {
            // left starts at i + 1 because i is checking for the first index
            int left = i + 1;
            int right = n - 1;

            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int sum = nums[i] + nums[left] + nums[right];

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // skip dupe for left and right
                    while (left < right && nums[left] == nums[left+1]) {left++;}
                    while (left < right && nums[right] == nums[right - 1]) {right--;}

                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //have two pointers
        //the sum of two the pointers must equal the number at index nums[i]
        //if yes then add the two pointers indices and the number @index
        //after iterate through and find none then return empty array

        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++){
            //start at left i + 1
            //end starts right n - 1
            int left = i + 1;
            int right = n - 1;

            //skip duplicate values
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    //skip dulicate values for left and right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (total < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

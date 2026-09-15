class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // use two pointers
        // start both r and l at 1 because the first element is always unique
        int l = 1;
        for (int r = 1; r < nums.size(); r++) {
            // check previous number if they are not the same then update
            if (nums[r] != nums[r-1]) {
                nums[l++] = nums[r];
            }
        }

        return l;
    }
};
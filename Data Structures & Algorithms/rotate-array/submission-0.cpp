class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // modify an array in-place
        // for each number record their new index by adding 
        vector<int> newPos(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int newIndex = (i + k) % nums.size();
            newPos[newIndex] = nums[i]; 
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = newPos[i];
        }
    }
};
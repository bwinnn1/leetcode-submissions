class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // non-decreasing means strictly increasing?
        // use a set because it sorts and eliminates duplicates automatically
        set<int> rmvDupe(nums.begin(), nums.end());
        int i = 0;
        for (int num : rmvDupe) {
            // for each number in the set
            nums[i++] = num;
        }
        return rmvDupe.size();
    }
};
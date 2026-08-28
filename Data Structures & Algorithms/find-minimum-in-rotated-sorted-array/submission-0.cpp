class Solution {
public:
    int findMin(vector<int> &nums) {
        // don't you just go and find the min number?
        // already sorted in the ascending order
        // unique so no two or more of the same numbers
        // if search -> O(n) 

        // binary search
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // find mid point. avoid overflows
            int mid = left + (right - left) / 2;

            // condition 
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // left == right -> pointing at the minimum
        return nums[left];
    }
};

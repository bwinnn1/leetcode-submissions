class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // nums containing n + 1 integers
        // each integer is in the range [1, n] inclusive

        // n = 5
        
        // nums = [1, 3, 2, 5, 2]

        // since nums[i] is within n+1. so each index points to another one  to the next index.

        // because one number is duplicated - there will be two indices point to the same number

        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // find a point in the cycle to find the entrance to the cycle
            // a reference point
            if (slow == fast) {
                break;
            }
        }

        // phase 2: find the entrance
        // where the entrance begins is the duplicate number
        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            // where they meet will be the entry point to the cycle
            if (slow == slow2) {
                return slow;
            }
        }
    }
};

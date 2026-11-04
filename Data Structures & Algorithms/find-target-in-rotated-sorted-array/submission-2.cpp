class Solution {
public:
    int search(vector<int>& nums, int target) {
        // objective: return the index of the target, -1 if not 
        // odd and even
        int n = nums.size();
        
        // if mid+1 is bigger than right => target will in left = mid + 1 to right

        // other the target lies in the other half

        // this is due to sorted array initially

        int l = 0; 
        int r = n - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int pivot = l;
        l = 0;
        r = n - 1;

        // right half is sorted in ascending order from the pivot
        // if nums[mid+1] < target < nums[r]
        if (nums[pivot] <= target && target <= nums[r]) {
            l = pivot;
        } else {
            // if not then it's on the other half
            r = pivot - 1;
        }

        // then do basic binary search for each halve
        while (l <= r) {
            int mid = (l+r) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }
};

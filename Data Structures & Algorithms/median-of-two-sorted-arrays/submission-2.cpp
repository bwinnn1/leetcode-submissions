class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // group two vectors together


        // nums1 = [101, 120, 902 , 903] [101, 120, 902]
        // nums2 = [500, 501, 7001, 9000] 

        // 101 120 500 501 902 903 7001 9000
        // 501 + 902 = 1403 / 2 
        
        // 101 120 500 501 902 7001 9000

        // check for odd and even arrays
        // if one array is odd -> odd final array -> work from there
        // both odd or both even -> even final array -> work from there

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int half = (m + n + 1) / 2; // total size needed of the left half

        int low = 0;
        int high = m;

        // search left half
        while (low <= high) {
            int i = low + (high - low) / 2; // find the portion of nums1 left side
            int j = half - i; // then the portion of nums2 left side

            int left1;
            if (i == 0) {
                left1 = INT_MIN; // negative infinity on the left
            } else {
                left1 = nums1[i - 1]; // nums[i] is right1 min
            }

            // maximum of the left side of nums2
            int left2;
            if (j == 0) {
                left2 = INT_MIN;
            } else {
                left2 = nums2[j - 1];
            }

            // find the maximum of right1
            int right1;
            if (i == m) {
                right1 = INT_MAX;
            } else {
                right1 = nums1[i];
            }

            int right2;
            if (j == n) {
                right2 = INT_MAX;
            } else {
                right2 = nums2[j];
            }

            // valid cut
            if (left1 <= right2 && left2 <= right1) {
                // even
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }
                // odd size
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else if (left1 > right2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};

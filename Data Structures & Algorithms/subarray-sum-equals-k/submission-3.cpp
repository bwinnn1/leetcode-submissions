class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int runningSum = 0;

        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        for (int num : nums) {
            runningSum += num;
            int diff = runningSum - k;
            //diff - runningSum = -k
            //runningSum - diff = k -> the difference between the current sum must equal k to know if that there's a subarray that adds up to that number

            result += prefixSum[diff];
            prefixSum[runningSum]++;
        }

        return result;
    }
};
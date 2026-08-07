class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // do binary search for edge case
        // if every number is larger than the target then return empty 

        //do two pointers and iterate through the list
        // one pointer at the front and the other at the rear

        // 1 2 3 4
        // ^     ^ 

        //target is 3

        // 1 2 3 4
        // ^   ^ 

        // output is 1-indexed means starting at 1
        for (int i = 0; i < numbers.size(); i++){
            int complement = target - numbers[i];
            //both need to be reset for each i
            int left = i + 1;
            int right = numbers.size()-1;

            while(left <= right){
                int mid = left + (right - left) / 2;
                // add left because we need a starting point

                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < complement) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return {};
    }
};

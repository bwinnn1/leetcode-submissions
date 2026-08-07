class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //make a set
        //check at each number in nums . if the num - 1 exists -> not a start of a sequence
        // if num - 1 not exist then it is a start of a sequence
        // then set length = 1
        //and check if num + length = 1, num + length = 2, ... until it is not in
        // in the set anymore
        // while update counter


        unordered_set<int> numSet(nums.begin(), nums.end());
        int counter = 0;

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) { 
                //if numSet.end() is a "not found" flag. if something it is not in the set: it called end() . Reads as: "did find come back empty-handed?"
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                counter = max(counter, length);
            }
        }
        return counter;
    }
};

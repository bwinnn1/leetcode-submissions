class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v_pair;

        for(int i=0; i<nums.size();i++){
            v_pair.push_back({nums[i], i});
        }

        sort(v_pair.begin(), v_pair.end());

        int i = 0, j = nums.size() - 1;
        while ( i<j) {
            int val = v_pair[i].first + v_pair[j].first;

            if (val == target) {
                return {min(v_pair[i].second, v_pair[j].second),
                        max(v_pair[i].second, v_pair[j].second)};
            } else if (val < target) {i++;}
            else {j--;}
        }
        return {};
    }
};

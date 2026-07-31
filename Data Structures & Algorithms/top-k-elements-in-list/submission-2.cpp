class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;

        //whenever we see a number, add it on the hashmap
        //return numbers that have same or more frequency as k
        for (const auto& s : nums){
            counter[s]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& each : counter){
            arr.push_back({each.second, each.first});
        }
        sort(arr.rbegin(), arr.rend()); //use rbegin() and rend() to sort in descending order
        vector<int> result;
        for (int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }
        return result;
    }
};

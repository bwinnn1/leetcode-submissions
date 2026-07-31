class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //a is 97, b is 98
        // total num of a + c + 
        //use hashmap to group them
        // to make a hashmap
        unordered_map<string, vector<string>> res;
        //use const auto& to avoid modify the original data
        for (auto& s: strs) {
            vector<int> count(26, 0);
            for (char ch : s) {
                count[ch - 'a']++; //minus a because a is 0
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> output;
        for (auto& pair : res){
            output.push_back(pair.second); //pair.first = the key value (1,0,0,1,...)
            //pair.second = the arrays
        }
        return output;
    }
};

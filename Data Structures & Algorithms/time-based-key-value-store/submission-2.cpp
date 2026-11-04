class TimeMap {
public:
    // parallel has map the store the key [(name), (time->value (happy, sad))
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
        // map[key] = [timestamp and its value]
        // timestamp is added in increasing order
    }
    
    // look up key's history
    // use upper_bound to jump to the first entry that is too new
    string get(string key, int timestamp) {
        // if key is not in map then return nothing ("")
        auto found = store.find(key);
        if (found == store.end()) {return "";}

        // get the list of the timpstamp with its values from found->second
        vector<pair<int, string>>& history = found->second;

        int left = 0;
        int right = (int)history.size() - 1;
        string answer = "";


        // search the history array to find the apt timpstamp to report
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (history[mid].first <= timestamp) {
                // returns the value that set was called previously
                // previous closest value to the left
                // t = 1 - sad 
                // t = 3 - happy

                // timestamp = 2 -> return t = 1 - sad not t = 3. 
                answer = history[mid].second;
                left = mid + 1;
            } else {
                // means the timestamp is too new (or to right)
                right = mid - 1;
            }
        }

        return answer;
    }
};

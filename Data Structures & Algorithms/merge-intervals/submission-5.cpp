class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //find a common number between each
        //sort by start time so if the end time of one interval is <= start time 
        //then merge them. 
        // otherwise:
        // just add the interval onto the result array
        vector<vector<int>> result; 
        sort(intervals.begin(), intervals.end());

        //now the result array is empty - nothing to check yet
        //so push the first interval on
        result.push_back(intervals[0]);

        for (auto& interval : intervals) {
            //take the current interval on the result array's last number
            int lastNum = result.back()[1];
            int start = interval[0];
            //use end as lastNum later
            int end = interval[1];

            if (start <= lastNum) {
                result.back()[1] = max(lastNum, end);
            } else {
                result.push_back({start, end});
            }
        }
        return result;
    }
};

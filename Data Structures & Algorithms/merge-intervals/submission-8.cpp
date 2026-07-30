class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //if first num of the array is smaller or equal to the last num of the prev array
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        //now the result array is empty
        result.push_back(intervals[0]);

        //[[1,3]]

        for (auto& interval : intervals){
            int lastNum = result.back()[1];
            int start = interval[0];
            int end = interval[1];

            if (start <= lastNum) {
                //[[1,5], [2,3]]
                if (end <= lastNum) {
                    result.back()[1] = lastNum;
                } else {
                    result.back()[1] = end;
                }
            } else {
                result.push_back({start, end});
            }
        }
        return result;
    }
};

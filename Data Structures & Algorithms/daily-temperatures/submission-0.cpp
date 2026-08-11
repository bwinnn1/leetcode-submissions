class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // default to 0 (covers "no warmer day" case)

        // Walk right to left, building on answers we've already computed
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;  // start by checking the very next day

            // Keep jumping forward using stored results until we either
            // find a warmer day, or run out of useful days to check
            while (j < n && temperatures[j] <= temperatures[i]) {
                if (result[j] == 0) {
                    // day j never found a warmer day either -> neither will i
                    j = n;  // force exit, leave result[i] as 0
                } else {
                    j = j + result[j];  // jump to the next day that is warmer from j
                    // since j is already calculated before i, it knows exactly how many warmer day it has to jump to
                }
            }

            if (j < n) {
                result[i] = j - i;  // found a warmer day, record the distance
            }
            // else: result[i] stays 0, already set by default
        }

        return result;
    }
};

#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // condition:
        // 1. determine the amount of banana to eat (rate of eating k)
        //     -> it has something to do with hours and each piles[i]
        // 2. If the pile has less than k bananas
        //     -> you may finish eating the pile but you can not eat from another pile in the same hour.
        // objective:
        // 1. return the MINIMUM integer k or eating rate k within h hours

        // question:
        // is there a limit of k - or is there a limit on how many bananas we can have per hour

        // edge:
        // 1. lower hours -> higher eating rate k
        // 2. we cannot eat fraction of a banana - 2.5 
        // 3. if piles.length == hours -> the eating rate == highest number of bananas in piles[i]

        int low = 1; // eating at least 1 banana per hour
        int high = *max_element(piles.begin(), piles.end());
        int result = high; // store result

        while (low <= high) {
            int k = (low + high) / 2; // eating rate k or mid point
            
            // simulate the time it takes to finish the entire piles with eating rate k
            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k); 
            }

            // we need to find smaller eating rate k because the question demanded minimum
            if (totalTime <= h) {
                // this eating rate k works with this many hours but we need to find smaller eating rate
                result = k;
                high = k - 1;
            } else {
                /// this minimum eating rate k is to slow (total time it takes > hours) so we need to eat faster or increase eating rate k
                low = k + 1;
            }
        }

        return result;
    }
};

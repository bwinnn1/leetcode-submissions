class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // pos : 1 4
        // speed : 3 2 

        // iteration
        // 1 4 7 10
        // 4 6 8 10  -> same car fleet

        // car at furthest pos will arrive first depends on their speed
        // destination - curr pos = remaining miles
        // you have the travel speed -> how many iteration to get there
        // 10 - 1 = 9 -> 3 miles/hours -> 3 hours
        // if car at each pos has the same hours == fleet

        // find out when those cars catch up with one another and then they're traveling at same speed
        int n = position.size();
        vector<pair<int,int>> cars; // (position, speed)
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end()); // sorts by position (first element) automatically, keeps speed attached
        
        
        int fleet = 0;  
        double leadingSoloTime = 0.0;
        // access the car closest to the target which is n - 1
        for (int i = n - 1; i >= 0; i--) {
            // get current pos
            double pos = cars[i].first;
            // get current speed
            double speed = cars[i].second;

            double soloT = (target - pos) / speed;

            // this car takes longer and won't able to merge and catch up. So its time becomes the new threshold
            if (soloT > leadingSoloTime) {
                fleet++;
                leadingSoloTime = soloT;
            }
        }

        return fleet;
    }
};

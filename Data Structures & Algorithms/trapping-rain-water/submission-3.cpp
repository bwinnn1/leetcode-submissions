class Solution {
public:
    int trap(vector<int>& height) {
        //find the max on the left and find the max on the right at each heigh[i]
        //then add them all together
        if (height.size() == 0){
            return 0;
        }
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());

        maxLeft[0] = height[0];
        maxRight[height.size() - 1] = height[height.size() - 1];

        for (int i = 1; i < height.size(); i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }

        for (int i = (int)height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }

        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            result += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return result;
    }
};

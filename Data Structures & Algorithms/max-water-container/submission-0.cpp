class Solution {
public:
    int maxArea(vector<int>& heights) {
        // max area is the one with the longest width and tallest height
        // use two pointers to check for the height
        // set the right height at the most right
        // compute the max area as we iterate through the array
        // if there's a max area size is bigger as the left pointer move
        // update it
        int maxArea = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int width = right - left;
            int length = min(heights[left], heights[right]);
            maxArea = max(maxArea, width * length);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

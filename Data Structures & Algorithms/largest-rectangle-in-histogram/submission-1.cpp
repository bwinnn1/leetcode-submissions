#include <algorithm>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // one side has to be bigger to another
        // w > l or l < w

        // the minimum would be height X 1 is 

        // given the height of each bar with their max width is 1
        // two loops one for the width 
        
        int n = heights.size();
        // left and right array. why: record the stop wall for each bar
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> st;

        // nothing can be further than -1 and height.size()

        // we do left wall for each bar first
        for (int i = 0; i < n; i++) {
            // if heights[of current top i]
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                // why: the bottle is the higher bar, it's the ones that are shorter than the current bar i -> pop the higher one
                st.pop();
            }

            // after popping all the higher bars, the one left is the wall
            if (!st.empty()) {
                leftMost[i] = st.top();
            }

            // update the stack with the current bar for the next bar to compare to
            st.push(i);
        }

        // clear the stack for rightMost wall
        while(!st.empty()) {st.pop();}

        for (int i = n - 1; i >= 0; i--) {
            // same idea if stack is not empty
            // pop all of the higher bar from current to right most
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // whichever left from the stack is the right most wall
            if (!st.empty()) {
                rightMost[i] = st.top();
            }

            st.push(i);
        }

        // compute the max area of the rectangle
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightMost[i] - leftMost[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};

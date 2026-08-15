class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // iterate through the matrix and find the target
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == target) return true;
            }
        }
        return false;
    }
};

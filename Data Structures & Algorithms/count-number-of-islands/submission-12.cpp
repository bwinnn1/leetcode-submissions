class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int numIslands = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1'){
                    dfs(grid, r, c);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] == '0') {
            return;
        }
        //already visited
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]); //you want to access 1 in {0, 1} so using directions[i][1], if it's directions[i][0] then it only uses 0.
        }
    }
};

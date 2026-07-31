class Solution {
    //need a directions array to move in four directions
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int island = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';
        //discover all for four directions up, down, left, right
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]); //for example: grid[r][c] = (3, 5). 
            //then r + directions[i][0] = (4, 5) and (2, 5)
            //then c + directions[i][1] = (3, 6) and (3, 4)
        }
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);


        // loop through every cell
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int box = (r/3)*3 + (c/3);
                if (board[r][c] == '.') {
                    continue;
                } else if (rows[r].find(board[r][c]) != rows[r].end() || cols[c].find(board[r][c]) != cols[c].end() || boxes[box].find(board[r][c]) != boxes[box].end()) {
                    return false;
                } else {
                    rows[r].insert(board[r][c]);
                    cols[c].insert(board[r][c]);
                    boxes[box].insert(board[r][c]);
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int rows, cols;

    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        if (idx == word.length()) return true;

        
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#'; 

        for (auto &dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if (find(board, newi, newj, idx + 1, word)) {
                return true;
            }
        }

        board[i][j] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

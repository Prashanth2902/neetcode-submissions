class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word, int r, int c, 
    vector<vector<bool>>& visited, int startIdx) {
        int rows = board.size();
        int cols = board[0].size();

        if(startIdx == word.size()) return true;

        if(r < 0 || c < 0 || r >= rows || c >= cols || 
        visited[r][c] || board[r][c] != word[startIdx]) return false;

        visited[r][c] = true;

        bool res = dfs(board, word, r + 1, c, visited, startIdx + 1) ||
                   dfs(board, word, r - 1, c, visited, startIdx + 1) ||
                   dfs(board, word, r, c + 1, visited, startIdx + 1) ||
                   dfs(board, word, r, c - 1, visited, startIdx + 1);

        visited[r][c] = false;
        return res;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++){
                if(dfs(board, word, i, j, visited, 0)) return true;
            }
        }
        return false;
    }
};

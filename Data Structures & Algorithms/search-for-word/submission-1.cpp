class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word,
    vector<vector<bool>>& visit, int idx, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();
        if(idx == word.size()) return true;
        if(min(r,c) < 0 || r == rows || c == cols || visit[r][c] || board[r][c] != word[idx]) return false;
        visit[r][c] = true;
        bool res = dfs(board, word, visit, idx+1, r+1, c) ||
                   dfs(board, word, visit, idx+1, r-1, c) ||
                   dfs(board, word, visit, idx+1, r, c+1) ||
                   dfs(board, word, visit, idx+1, r, c-1);
        visit[r][c] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++){
                if(dfs(board, word, visit, 0, r, c)) return true;
            }
        }
        return false;
    }
};

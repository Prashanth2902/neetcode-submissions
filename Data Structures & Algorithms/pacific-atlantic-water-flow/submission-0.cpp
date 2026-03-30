class Solution {
public:

    void dfs(int r, int c, vector<vector<bool>>& visit, vector<vector<int>>& heights) {
        visit[r][c] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto [dr, dc]: directions) {
            int nr = r + dr, nc = c + dc;
            if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() &&
            !visit[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, visit, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        for(int r=0;r<rows;r++){
            dfs(r, 0, pac, heights);
            dfs(r, cols-1, atl, heights);
        }
        for(int c=0;c<cols;c++){
            dfs(0, c, pac, heights);
            dfs(rows-1, c ,atl, heights);
        }
        vector<vector<int>> res;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pac[r][c] && atl[r][c]) {
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};

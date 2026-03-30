class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(min(r,c) < 0 || r == rows || c == cols || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r+1,c)
        + dfs(grid, r-1,c)
        + dfs(grid, r,c+1)
        + dfs(grid, r,c-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};

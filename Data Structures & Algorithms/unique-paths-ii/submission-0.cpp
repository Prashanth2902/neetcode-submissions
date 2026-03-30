class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& cache) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(r == rows || c == cols || grid[r][c] == 1) return 0;
        if(r == rows - 1 && c == cols - 1) return 1;
        if(cache[r][c] != -1) return cache[r][c];
        return cache[r][c] = dfs(grid, r+1, c, cache) + dfs(grid, r, c+1, cache);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> cache;
        cache.resize(rows, vector<int>(cols, -1));
        return dfs(obstacleGrid, 0, 0, cache);
    }
};
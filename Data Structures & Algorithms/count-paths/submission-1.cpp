class Solution {
public:
    int dfs(int r, int c, int m, int n, vector<vector<int>>& cache) {
        if(r == m-1 || c == n-1) return 1;
        if(r >= m || c >= n) return 0;
        if(cache[r][c] != -1) return cache[r][c];
        return cache[r][c] = dfs(r+1, c, m, n, cache) + dfs(r, c+1, m, n, cache);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> cache;
        cache.resize(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, cache);
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0},
                                     {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        q.push({0,0,1});
        visit[0][0] = true;
        while(!q.empty()) {
            auto [r,c,len] = q.front();
            q.pop();
            if(r == n-1 && c == n-1) return len;
            for(auto [dr,dc]: dir) {
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && !visit[nr][nc]) {
                    q.push({nr, nc, len + 1});
                    visit[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};
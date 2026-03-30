class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == 0)
                    q.push({r,c});
            }
        }
        
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if(min(r, c) < 0 || r == rows || c == cols || grid[r][c] != INT_MAX) continue;

                grid[r][c] = grid[row][col] + 1;
                q.push({r,c});
            }

        } 
    }
};

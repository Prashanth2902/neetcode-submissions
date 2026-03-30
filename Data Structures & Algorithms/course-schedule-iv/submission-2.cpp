class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adj(n ,vector<bool>(n, false));
        vector<bool> res;
        for(auto pre: prerequisites){
            adj[pre[0]][pre[1]] = true;
        }
        for(int k=0;k<n;k++) {
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
                }
            }
        }
        for(auto q: queries) {
            res.push_back(adj[q[0]][q[1]]);
        }
        return res;
    }
};
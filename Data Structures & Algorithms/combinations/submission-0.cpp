class Solution {
public:

    void dfs(int i, vector<vector<int>>& res, vector<int>& subRes, int n, int k) {
        if(subRes.size() == k) {
            res.push_back(subRes);
            return;
        }
        if(i>n) return;
        subRes.push_back(i);
        dfs(i+1, res, subRes, n, k);
        subRes.pop_back();
        dfs(i+1, res, subRes, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subRes;
        dfs(1, res, subRes, n, k);
        return res;
    }
};
class Solution {
public:

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subres, vector<bool>& visit) {
        if(subres.size() == nums.size()) {
            res.push_back(subres);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(visit[i]) continue;
            visit[i] = true;
            subres.push_back(nums[i]);
            dfs(nums, res, subres, visit);
            subres.pop_back();
            visit[i] = false;
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subres;
        vector<bool> visit(nums.size(), false);
        dfs(nums, res, subres, visit);
        return res;
    }
};

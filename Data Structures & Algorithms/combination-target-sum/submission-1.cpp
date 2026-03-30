class Solution {
public:

    void dfs(int i, vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& subres) {
        if(target < 0 || i >= nums.size()) return;
        if(target == 0) {
            res.push_back(subres);
            return;
        }
        dfs(i+1, nums, target, res, subres);
        subres.push_back(nums[i]);
        dfs(i, nums, target - nums[i], res, subres);
        subres.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subres;
        dfs(0, nums, target, res, subres);
        return res;
    }
};

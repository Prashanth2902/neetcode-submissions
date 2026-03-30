class Solution {
public:

    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int>& subres,
    int i, int target) {
        if(target == 0) {
            res.push_back(subres);
            return;
        }

        if(target < 0 || i >= nums.size()) return;

        subres.push_back(nums[i]);
        dfs(nums, res, subres, i, target - nums[i]);
        subres.pop_back();
        dfs(nums, res, subres, i + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subres;
        dfs(nums, res, subres, 0, target);
        return res;
    }
};

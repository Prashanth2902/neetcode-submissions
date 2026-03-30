class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, int startIdx, vector<int>& subRes) {
        if(nums.size() == startIdx) {
            res.push_back(subRes);
            return;
        }
        subRes.push_back(nums[startIdx]);
        dfs(nums, res, startIdx + 1, subRes);
        subRes.pop_back();
        dfs(nums, res, startIdx + 1, subRes);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subRes;
        dfs(nums, res, 0, subRes);
        return res;
    }
};

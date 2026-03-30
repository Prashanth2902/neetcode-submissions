class Solution {
public:

    int dfs(int l, int r, vector<int>& nums, vector<int>& dp) {
        if(l > r) return 0;
        if(dp[l] != -1) return dp[l];
        int skip = dfs(l+1, r, nums, dp);
        int include = nums[l] + dfs(l+2, r, nums, dp);
        return dp[l] = max(skip, include);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(dfs(0, nums.size() - 2, nums, dp1), dfs(1, nums.size() - 1, nums, dp2));
    }
};

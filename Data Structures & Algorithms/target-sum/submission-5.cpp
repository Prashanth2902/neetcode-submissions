class Solution {
public:

    int dfs(int i, int curr, vector<int>& nums, int target, vector<vector<int>>& cache, int sum) {
        if(i == nums.size()) {
            return curr == target ? 1:0;
        }
        if(cache[i][curr+sum] != -1) return cache[i][curr+sum];
        return cache[i][curr+sum] = dfs(i+1, curr+nums[i], nums, target, cache, sum) + 
        dfs(i+1, curr-nums[i], nums, target, cache, sum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> cache(nums.size(), vector<int>(2*sum+1, -1));
        return dfs(0, 0, nums, target, cache, sum);
    }
};

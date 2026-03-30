class Solution {
public:

    bool dfs(vector<int> nums, int i, vector<vector<int>>& cache, int target) {
        if(i == nums.size()) return target == 0;
        if(target < 0) return false;
        if(cache[i][target] != -1) return cache[i][target];
        cache[i][target] = dfs(nums, i+1, cache, target) || dfs(nums, i+1, cache, target-nums[i]);
        return cache[i][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if(sum%2!=0) return false;
        vector<vector<int>> cache(nums.size(), vector<int>(sum/2 + 1, -1));
        return dfs(nums, 0, cache, sum/2);
    }
};

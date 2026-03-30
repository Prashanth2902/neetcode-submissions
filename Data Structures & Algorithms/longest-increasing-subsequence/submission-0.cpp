class Solution {
public:

    int dfs(int i, int j, vector<int>& nums, vector<vector<int>>& cache) {
        if(i == nums.size()) {
            return 0;
        }
        if(cache[i][j+1] != -1) return cache[i][j+1];

        int res = dfs(i+1, j, nums, cache);

        if(j == -1 || nums[j] < nums[i]) {
            res = max(res, 1 + dfs(i+1, i, nums, cache));
        }

        cache[i][j+1] = res;
        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cache(n, vector<int>(n+1, -1));
        return dfs(0, -1, nums, cache);
    }
};

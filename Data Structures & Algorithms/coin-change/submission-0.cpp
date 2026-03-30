class Solution {
public:

    int dfs(int i, vector<int>& coins, int amount, vector<vector<int>>& cache) {
        if(i == coins.size() || amount < 0) return 10001;
        if(amount == 0) return 0;
        if(cache[i][amount] != -1) return cache[i][amount];
        int skip = dfs(i+1, coins, amount, cache);
        int include = 1 + dfs(i, coins, amount - coins[i], cache);
        cache[i][amount] = min(include, skip);
        return cache[i][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> cache(coins.size(), vector<int>(amount+1, -1));
        int res = dfs(0, coins, amount, cache);
        return res > 1000 ? -1: res;
    }
};

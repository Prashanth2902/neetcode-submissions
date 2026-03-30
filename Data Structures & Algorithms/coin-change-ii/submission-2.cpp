class Solution {
public:

    int dfs(int i, int amount, vector<int>& coins, vector<vector<int>>& cache) {
        if(amount < 0 || i == coins.size()) return 0;
        if(amount == 0) return 1;
        if(cache[i][amount] != -1) return cache[i][amount];
        int skip = dfs(i+1, amount, coins, cache);
        int take = dfs(i, amount-coins[i], coins, cache);
        return cache[i][amount] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> cache(coins.size(), vector<int>(amount+1, -1));
        return dfs(0, amount, coins, cache);
    }
};

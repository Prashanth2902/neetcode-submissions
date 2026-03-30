class Solution {
public:

    int dfs(int i, int amount, vector<int>& coins, vector<vector<int>>& res) {
        if(i == coins.size()) return 0;
        if(amount == 0) {
            return 1;
        }
        if(amount < 0) return 0;
        if(res[i][amount] != 0) return res[i][amount];
        int skip = dfs(i+1, amount, coins, res);
        int take = dfs(i, amount - coins[i], coins, res);
        return res[i][amount] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> res (coins.size(), vector<int>(amount + 1, 0));
        return dfs(0, amount, coins, res);
    }
};

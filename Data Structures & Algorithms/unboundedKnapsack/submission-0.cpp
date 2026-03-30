class Solution {
public:

    int dfs(int i, vector<int>& profit, vector<int>& weight, int capacity, vector<vector<int>>& cache) {
        if(i == profit.size()) {
            return 0;
        }
        if(cache[i][capacity] != -1) return cache[i][capacity];
        int skip = dfs(i+1, profit, weight, capacity, cache);
        int include = 0;
        if(capacity - weight[i] >= 0) {
            include = profit[i] + dfs(i, profit, weight, capacity - weight[i], cache);
        }
        cache[i][capacity] = max(skip, include);
        return cache[i][capacity];
    }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> cache(profit.size(), vector<int>(capacity + 1, -1));
        return dfs(0, profit, weight, capacity, cache);
    }
};

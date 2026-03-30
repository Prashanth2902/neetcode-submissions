class Solution {
public:

    int dfs(int i, vector<int>& profit, vector<int>& weight, int capacity, vector<vector<int>>& cache) {
        if(i == weight.size() || capacity == 0) return 0;
        if(cache[i][capacity] != -1) return cache[i][capacity];
        int skip = dfs(i+1, profit, weight, capacity, cache);
        int include = 0;
        if (capacity - weight[i] >= 0) {
            include = profit[i] + dfs(i+1, profit, weight, capacity - weight[i], cache);
        }
        return cache[i][capacity] = max(include, skip); 
    }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> cache(profit.size(), vector<int>(capacity + 1, -1));
        return dfs(0, profit, weight, capacity, cache);
    }
};

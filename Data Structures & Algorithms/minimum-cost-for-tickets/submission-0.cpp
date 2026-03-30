class Solution {
public:

    int dfs(int i, vector<int>& days, vector<int>& costs, vector<int>& cache) {
        if(i>=days.size()) return 0;
        if(cache[i] != -1) return cache[i];

        int op1 = costs[0] + dfs(i+1, days, costs, cache);

        int nextIdx7 = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
        int op2 = costs[1] + dfs(nextIdx7, days, costs, cache);

        int nextIdx30 = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
        int op3 = costs[2] + dfs(nextIdx30, days, costs, cache);

        return cache[i] = min(min(op1, op2), op3);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cache(days.size(), -1);
        return dfs(0, days, costs, cache);
    }
};
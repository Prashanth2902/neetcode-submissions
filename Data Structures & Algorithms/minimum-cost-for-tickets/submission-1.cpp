class Solution {
public:

    int dfs(int idx, vector<int>& days, vector<int>& costs, vector<int>& cache) {
        if(idx >= days.size()) return 0;
        if(cache[idx] != -1) return cache[idx];

        int opt1 = costs[0] + dfs(idx + 1, days, costs, cache);

        int j = idx;
    while (j < days.size() && days[j] < days[idx] + 7) {
        j++;
    }

    int opt2 = costs[1] + dfs(j, days, costs, cache);
    int k = idx;
    
    while (k < days.size() && days[k] < days[idx] + 30) {
        k++;
    }

    int opt3 = costs[2] + dfs(k, days, costs, cache);

    return cache[idx] = min(min(opt1, opt2), opt3);
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cache(days.size(), -1);
        return dfs(0, days, costs, cache);
    }
};
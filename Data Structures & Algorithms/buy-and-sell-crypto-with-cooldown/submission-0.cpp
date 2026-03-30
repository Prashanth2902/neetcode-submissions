class Solution {
public:

    int dfs(int i, vector<int>& prices, unordered_map<string, int>& m, bool buying) {
        if(i >= prices.size()) return 0;
        string key = to_string(i) + "-" + to_string(buying);
        if(m.count(key)) return m[key];
        int cd = dfs(i+1, prices, m, buying);
        if(buying) {
            int buy = dfs(i+1, prices, m, false) - prices[i];
            m[key] = max(buy, cd);
        } else {
            int sell = dfs(i+2, prices, m, true) + prices[i];
            m[key] = max(sell, cd);
        }
        return m[key];
    }

    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> m;
        return dfs(0, prices, m, true); 
    }
};

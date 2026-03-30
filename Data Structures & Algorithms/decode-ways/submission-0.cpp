class Solution {
public:

    int dfs(int i, string s, unordered_map<int,int>& dp) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp.count(i)) return dp[i];
        
        int res = dfs(i+1, s, dp);
        if(i+1 < s.size() &&
        (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
            res += dfs(i+2, s, dp);
        }
        dp[i] = res;
        return res;
    }

    int numDecodings(string s) {
        unordered_map<int,int> dp;
        dp[s.size()] = 1;
        return dfs(0, s, dp);
    }
};

class Solution {
public:

    int dfs(string s, string t, vector<vector<int>>& cache, int i, int j) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(cache[i][j] != -1) return cache[i][j];
        int res = dfs(s, t, cache, i+1, j);
        if(s[i] == t[j]) {
            res += dfs(s, t, cache, i+1, j+1);
        }
        return cache[i][j] = res;
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(n > m) return 0;
        vector<vector<int>> cache(m+1, vector<int>(n+1, -1));
        return dfs(s, t, cache, 0, 0);
    }
};

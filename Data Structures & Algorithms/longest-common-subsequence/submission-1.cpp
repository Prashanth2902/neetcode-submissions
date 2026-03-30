class Solution {
public:

    int dfs(string text1, string text2, int i, int j, vector<vector<int>>& cache) {
        if(i == text1.size() || j == text2.size()) return 0;
        if(cache[i][j] != -1) return cache[i][j];
        if(text1[i] == text2[j]) {
            cache[i][j] = 1 + dfs(text1, text2, i+1, j+1, cache);
        } else {
            cache[i][j] = max(dfs(text1, text2, i+1, j, cache), dfs(text1, text2, i, j+1, cache));
        }
        return cache[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache;
        cache.resize(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0, cache);
    }
};

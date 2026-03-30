class Solution {
public:

    int dfs(int i, int j, string s, string t, vector<vector<int>>& cache) {
        if(i == s.size()) return t.size() - j;
        if(j == t.size()) return s.size() - i;
        if(cache[i][j] != -1) return cache[i][j];
        if(s[i] == t[j]) {
            cache[i][j] = dfs(i+1,j+1, s, t, cache);
        } else {
            int res = min(dfs(i,j+1, s, t, cache), min(dfs(i+1,j, s, t, cache), dfs(i+1,j+1, s, t, cache)));
            cache[i][j] = res + 1;
        }
        return cache[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> cache(word1.size()+1, vector<int>(word2.size()+1, -1));
        return dfs(0, 0, word1, word2, cache);
    }
};

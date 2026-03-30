class Solution {
public:

    int dfs(int i, int j, string word1, string word2, int m, int n, vector<vector<int>>& cache) {
        if(i == m) return n-j;
        if(j == n) return m-i;
        if(cache[i][j] != -1) return cache[i][j];
        if(word1[i] == word2[j]) {
            cache[i][j] = dfs(i+1, j+1, word1, word2, m, n, cache);
        } else {
            int res = min(dfs(i+1, j, word1, word2, m, n, cache), 
                          dfs(i, j+1, word1, word2, m, n, cache));
            res = min(res, dfs(i+1,j+1,word1,word2,m,n,cache));
            cache[i][j] = res + 1;
        }
        return cache[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(0,0,word1, word2, m, n, cache);
    }
};

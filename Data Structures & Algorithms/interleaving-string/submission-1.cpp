class Solution {
public:

    int dfs(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>& cache) {
        if(i == s1.size() && j == s2.size()) return k == s3.size();
        if(cache[i][j] != -1) return cache[i][j];
        bool res1 = false;
        bool res2 = false;
        if(s1[i] == s3[k]) {
            res1 = dfs(i+1, j, k+1, s1, s2, s3, cache);
        }
        if(s2[j] == s3[k]) {
            res2 = dfs(i, j+1, k+1, s1, s2, s3, cache);
        }
        return cache[i][j] = res1 || res2; 
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> cache(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(0, 0, 0, s1, s2, s3, cache);
    }
};

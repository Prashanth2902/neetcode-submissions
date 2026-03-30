class Solution {
public:

    bool dfs(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>& cache) {
        if(k == s3.length()) {
            return (i == s1.length()) && (j == s2.length());
        }
        if(cache[i][j] != -1) return cache[i][j];
        bool res = false;
        if(i < s1.length() && s1[i] == s3[k]) {
            res = dfs(i+1,j,k+1,s1,s2,s3,cache);
        }
        if(!res && j < s2.length() && s2[j] == s3[k]) {
            res = dfs(i,j+1,k+1,s1,s2,s3,cache);
        }
        return cache[i][j] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m+n != s3.size()) return false;
        vector<vector<int>> cache(m+1, vector<int>(n+1, -1));
        return dfs(0,0,0,s1,s2,s3,cache);
    }
};

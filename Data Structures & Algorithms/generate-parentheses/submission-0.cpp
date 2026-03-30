class Solution {
public:

    void dfs(int n, vector<string>& res, string& subres, int open, int close) {
        if(open == close && open == n) {
            res.push_back(subres);
            return;
        }
        if(open < n) {
            subres += '(';
            dfs(n, res, subres, open+1, close);
            subres.pop_back();
        }
        if(close < open) {
            subres += ')';
            dfs(n, res, subres, open, close+1);
            subres.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subres;
        dfs(n, res, subres, 0, 0);
        return res;
    }
};

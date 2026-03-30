class Solution {
public:

    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    void dfs(string digits, vector<string>& res, string subres, int i) {
        if(subres.size() == digits.size()) {
            res.push_back(subres);
            return;
        }
        if(i>digits.size()) return;
        string chars = digitToChar[digits[i] - '0'];
        for(char c: chars) {
            dfs(digits, res, subres + c, i + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string subres = "";
        dfs(digits, res, subres, 0);
        return res;
    }
};

class Solution {
public:

    bool dfs(int i, string s, unordered_set<string>& wordset, unordered_map<int, bool>& m) {
        if(i == s.size()) return true;
        if(m.count(i)) return m[i];
        for(string word: wordset) {
            if(i + word.size() <= s.length() && s.substr(i, word.size()) == word) {
                if(dfs(i+word.size(), s, wordset, m)) {
                    m[i] = true;
                    return true;
                }
            }
        }
        return m[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> m;
        unordered_set<string> wordset(wordDict.begin(), wordDict.end()); 
        m[s.size()] = true;
        return dfs(0, s, wordset, m);
    }
};

class Solution {
public:

    bool dfs(char c, unordered_map<char, unordered_set<char>>& adj, 
    unordered_set<char>& visit, unordered_set<char>& visited, string& res) {
        if(visited.count(c)) return false;
        if(visit.count(c)) return true;
        visited.insert(c);
        for(auto x: adj[c]) {
            if(!dfs(x, adj, visit, visited, res)) return false;
        }
        visit.insert(c);
        visited.erase(c);
        res += c;
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        for(int i=0;i<words.size()-1;i++) {
            string word1 = words[i], word2 = words[i+1];
            if(word1.size() > word2.size() && word1.find(word2) == 0) return "";
            for(int j=0;j<min(word1.size(), word2.size());j++) {
                if(word1[j] != word2[j]) {
                    adj[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }
        string res = "";
        unordered_set<char> visit, visited;
        for(auto w: words) {
            for(char c: w) {
                if(!dfs(c, adj, visit, visited, res)) return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

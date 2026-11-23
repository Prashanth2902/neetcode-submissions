class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mmap;
        for(auto ss:strs) {
            string s = ss;
            sort(s.begin(), s.end());
            mmap[s].push_back(ss);
        }
        for(auto i:mmap) res.push_back(i.second);
        return res;

    }
};

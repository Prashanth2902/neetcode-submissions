class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return res;
        for(auto str: strs) {
            res += to_string(str.length()) + '#' + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if(s.empty()) return res;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int strlen = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j + 1, strlen));
            i = j + 1 + strlen;
        }
        return res;
    }
};

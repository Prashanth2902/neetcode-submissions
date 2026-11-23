class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(), strs.end());
        int m = strs[0].size(), n = strs.back().size();
        int minSize = min(m,n);
        for(int i=0;i<minSize;i++) {
            if(strs[0][i] == strs[strs.size()-1][i]) res += strs[0][i];
            else break;
        }
        return res;
    }
};
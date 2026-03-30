class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> tCount, window;
        for(int i = 0; i < t.size(); i++) {
            tCount[t[i]]++;
        }
        int have = 0;
        int need = tCount.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for(int r=0;r<s.size();r++){
            char c = s[r];
            window[c]++;
            
            if(tCount.count(c) && window[c] == tCount[c]) {
                have++;
            }

            while(have == need) {
                if((r-l+1) < resLen) {
                    resLen = r-l+1;
                    res = {l,r};
                }
                char a = s[l];
                window[a]--;
                if(tCount.count(a) && window[a] < tCount[a]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

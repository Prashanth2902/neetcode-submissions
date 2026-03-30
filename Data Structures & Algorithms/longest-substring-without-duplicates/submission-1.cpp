class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> charset;
        int l = 0;
        int ans = 0;
        for(int r=0;r<s.size();r++) {
            while(charset.count(s[r])) {
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

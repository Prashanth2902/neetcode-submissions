class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int length = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            while(m.find(s[r]) != m.end()) {
                m.erase(s[l]);
                l++;
            }
            m.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return length;
    }
};

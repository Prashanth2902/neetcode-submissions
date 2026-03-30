class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int maxSize = INT_MIN;
        int l = 0;
        int res = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            maxSize = max(maxSize, m[s[i]]);
            while ((i-l+1) - maxSize > k) {
                m[s[l]]--;
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;

    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> smap, tmap;
        for(auto c: s) smap[c]++;
        for(auto c: t) tmap[c]++;
        return smap == tmap;
    }
};

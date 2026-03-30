class Solution {
public:

    bool stringCheck(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;        
    }

    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        for(int i=0;i<s2.size()-k+1;i++){
            if(stringCheck(s1, s2.substr(i, k))) return true;
        }
        return false;
    }
};

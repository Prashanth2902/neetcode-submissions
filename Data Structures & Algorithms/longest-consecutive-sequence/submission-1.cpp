class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto n: nums) {
            if(s.count(n)) {
                int len = 1;
                while(s.count(n+len)){
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};

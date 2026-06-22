class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> numset(nums.begin(), nums.end());
        for(auto num: numset) {
            if(!numset.count(num-1)) {
                int len = 0;
                while(numset.count(num++)) {
                    len++;
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};

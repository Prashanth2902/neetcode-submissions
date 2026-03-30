class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for( auto num: numSet) {
            if(numSet.find(num - 1) == numSet.end()) {
                int len = 1;
                while(numSet.find(num + len) != numSet.end()) {
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};

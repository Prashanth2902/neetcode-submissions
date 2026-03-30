class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int curmin = 1, curmax = 1;
    
        for(auto num: nums) {
            int tmp = num*curmax;
            curmax = max(num, max(curmax*num, curmin*num));
            curmin = min(num, min(tmp, curmin*num));
            ans = max(ans, curmax);
        }

        return ans;
    }
};

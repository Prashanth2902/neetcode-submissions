class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pref(n);
        vector<int> suf(n);

        pref[0] = 1;
        suf[n-1] = 1;
        for(int i=1;i<n;i++) pref[i] = nums[i-1] * pref[i-1];
        for(int i = n - 2; i>=0;i--) suf[i] = nums[i+1] * suf[i+1];
        for(int i=0;i<n;i++) ans[i] = pref[i] * suf[i];
        return ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = 0, l = 0;
        int length = INT_MAX;
        for(int r = 0; r < nums.size(); r++) {
            total += nums[r];
            while(total >= target) {
                length = min(length, r - l + 1);
                total -= nums[l];
                l++;
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};
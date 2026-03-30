class Solution {
public:
    int findMin(vector<int> &nums) {
       int l = 0, r = nums.size() - 1;
       if(nums.size() == 1) return nums[0];
       while(l<r) {
            if(nums[l] < nums[r]) {
                return nums[l];
            } else {
                int m = l + (r-l)/2;
                if(nums[m] > nums[r]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }  
       }
       return nums[l];
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != val){
                nums[l++] = nums[i];
            }
        }
        return l;
    }
};
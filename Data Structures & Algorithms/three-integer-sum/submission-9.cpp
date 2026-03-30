class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> dummy;
                    dummy.push_back(nums[i]);
                    dummy.push_back(nums[j]);
                    dummy.push_back(nums[k]);
                    result.push_back(dummy);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};

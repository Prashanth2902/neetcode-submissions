class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> ss(nums.begin(), nums.end());
        return nums.size() != ss.size();
    }
};
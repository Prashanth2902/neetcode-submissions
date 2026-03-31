class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(auto n: nums) {
            counter[n]++;
        }

        vector<int> res;
        for(auto i: counter) {
            if(i.second > nums.size() / 3) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
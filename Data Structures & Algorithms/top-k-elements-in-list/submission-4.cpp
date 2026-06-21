class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for(auto x: nums) {
            m[x]++;
        }
        vector<pair<int, int>> temp;
        for(auto x: m) {
            temp.push_back({x.second, x.first});
        }
        sort(temp.rbegin(), temp.rend());
        int i=0;
        while(k--){
            res.push_back(temp[i++].second);
        }
        return res;
    }
};

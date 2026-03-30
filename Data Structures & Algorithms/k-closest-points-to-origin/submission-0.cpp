class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        for(auto& p: points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({dist, {p[0], p[1]}});
            if(maxHeap.size() > k) maxHeap.pop();
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
    }
};

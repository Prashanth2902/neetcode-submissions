class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int,int>>> adj;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        unordered_set<int> visit;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        minheap.push({0, 0});
        int res = 0;
        while(visit.size() < n){
            auto curr = minheap.top();
            minheap.pop();
            int w = curr.first, n = curr.second;
            if(visit.count(n)) continue;
            visit.insert(n);
            res += w;
            for(auto nei: adj[n]){
                int w2 = nei.first, n2 = nei.second;
                if(!visit.count(n2)){
                    minheap.push({w2, n2});
                }
            }
        }
        return res;
    }
};

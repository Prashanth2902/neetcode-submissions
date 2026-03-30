class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(int i=0;i<n;i++){
            adj[i] = vector<pair<int,int>>();
        }
        for(auto edge: edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d,w});
            adj[d].push_back({s,w});
        }
        unordered_set<int> visit;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minheap;
        for(auto nei: adj[0]) {
            int node = nei.first, w = nei.second;
            minheap.push({w, 0, node});
        }
        visit.insert(0);
        int totalWeight = 0;
        while(!minheap.empty() && visit.size() < n) {
            tuple<int,int,int> curr = minheap.top();
            minheap.pop();
            int w1 = get<0>(curr), s1 = get<1>(curr), d1 = get<2>(curr);
            if(visit.count(d1)) continue;
            totalWeight += w1;
            visit.insert(d1);
            for(auto edge: adj[d1]) {
                int nei = edge.first, wei = edge.second;
                if(!visit.count(nei)){
                    minheap.push({wei, d1, nei});
                }
            }
        }
        return visit.size() == n ? totalWeight: -1;
    }
};


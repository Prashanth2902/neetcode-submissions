class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i=0;i<n;i++){
            adj[i] = vector<pair<int, int>>();
        }
        for(auto edge: edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d,w});
        }
        unordered_map<int, int> shortest;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, src});
        while(!minHeap.empty()) {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int w1 = curr.first, n1 = curr.second;
            if(shortest.count(n1)) continue;
            shortest[n1] = w1;
            for(auto edge: adj[n1]) {
                int n2 = edge.first, w2 = edge.second;
                if(!shortest.count(n2)) {
                    minHeap.push({w1+w2, n2});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!shortest.count(i)){
                shortest[i] = -1;
            }
        }
        return shortest;
    }
};

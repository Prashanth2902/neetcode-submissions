class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double>>> adj;
        for(int i=0;i<n;i++){
            adj[i] = vector<pair<int,double>>();
        }
        for(int i=0;i<edges.size();i++) {
            int s = edges[i][0], d = edges[i][1];
            double w = succProb[i];
            adj[s].push_back({d,w});
            adj[d].push_back({s,w});
        }
        unordered_map<int, double> shortest;
        priority_queue<pair<double,int>> minheap;
        minheap.push({1, start_node});
        while(!minheap.empty()) {
            pair<double, int> curr = minheap.top();
            minheap.pop();
            double w1 = curr.first;
            int n1 = curr.second;
            if(shortest.count(n1)) continue;
            shortest[n1] = w1;
            for(auto edge: adj[n1]) {
                int n2 = edge.first;
                double w2 = edge.second;
                if(!shortest.count(n2)){
                    minheap.push({w1*w2, n2});
                }
            }
        }
        if(shortest.count(end_node)){
            return shortest[end_node];
        } else {
            return 0;
        }
    }
};
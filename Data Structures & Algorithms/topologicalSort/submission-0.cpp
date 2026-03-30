class Solution {
public:

    bool dfs(int src, unordered_map<int, vector<int>>& adj, unordered_set<int>& visit, unordered_set<int>& visiting, vector<int>& topsort) {
        if(visit.count(src)) return true;
        if(visiting.count(src)) return false;
        visiting.insert(src);
        for(auto x:adj[src]){
            if(!dfs(x, adj, visit, visiting, topsort)) return false;
        }
        visiting.erase(src);
        visit.insert(src);
        topsort.push_back(src);
        return true;
    }

    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<n;i++) {
            adj[i] = vector<int>();
        }
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> topsort;
        unordered_set<int> visit;
        unordered_set<int> visiting;
        for(int i=0;i<n;i++) {
            if(!dfs(i, adj, visit, visiting, topsort)) return {};
        }
        reverse(topsort.begin(), topsort.end());
        return topsort;
    }
};

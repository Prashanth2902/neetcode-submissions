class Solution {
public:

    bool dfs(int curr, unordered_map<int, vector<int>>& adj,
    unordered_set<int>& visit, unordered_set<int>& visiting, vector<int>& res) {
        if(visit.count(curr)) return true;
        if(visiting.count(curr)) return false;
        visiting.insert(curr);
        for(auto x: adj[curr]){
            if(!dfs(x, adj, visit, visiting, res)) return false;
        }
        visiting.erase(curr);
        visit.insert(curr);
        res.push_back(curr);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<numCourses;i++) {
            adj[i] = vector<int>();
        }
        for(auto edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> res;
        unordered_set<int> visit, visited;
        for(int i=0;i<numCourses;i++) {
            if(!dfs(i, adj, visit, visited, res)) return {};
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};

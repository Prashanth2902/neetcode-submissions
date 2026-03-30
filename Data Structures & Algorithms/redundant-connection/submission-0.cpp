class DSU {
public:
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(parent[rootX] != parent[rootY]) {
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n);

        for(auto edge: edges) {
            if(!dsu->unite(edge[0], edge[1])) {
                return vector<int>{edge[0], edge[1]};
            }
        }
        return {};
    }
};

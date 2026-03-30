class DSU {
public:

    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) {
            return false;
        } else {
            if(parent[rootX] > parent[rootY]) {
                parent[rootY] = parent[rootX];
            } else if (parent[rootX] < parent[rootY]) {
                parent[rootX] = parent[rootY];
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            return true;
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        int res = n;
        for(auto edge: edges){
            if(dsu->unite(edge[0], edge[1])) res--;
        }
        return res;
    }
};

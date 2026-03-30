class DSU {
public:

    vector<int> parent;
    vector<int> rank;
    int comp;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        comp = n;
        for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) {
            return false;
        } else {
            comp--;
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            return true;
        }
    }

    int getComp() {
        return comp;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        for(auto edge: edges){
            if(!dsu->unite(edge[0], edge[1])) return false;
        }
        return dsu->getComp() == 1;
    }
};

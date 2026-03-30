class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int count;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        count = n;
        for(int i=0;i<n;i++){
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
            count--;
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
        return count;
    }

};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap; 
        for (const auto& edge : edges) {
            minHeap.push(make_tuple(edge[2], edge[0], edge[1]));
        }
        DSU* dsu = new DSU(n);
        int res = 0;
        while(!minHeap.empty()) {
            tuple<int,int,int> curr = minHeap.top();
            minHeap.pop();
            int w = get<0>(curr), n1 = get<1>(curr), n2 = get<2>(curr);
            if(dsu->unite(n1, n2)){
                res += w;
            }
        }
        return dsu->getComp() != 1 ? -1 : res;
    }
};

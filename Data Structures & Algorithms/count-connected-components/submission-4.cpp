class DSU {

private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        int x = node;
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) {
            return false;
        }

        if(rank[py] > rank[px]) {
            swap(px, py);
        }

        parent[py] = px;
        rank[px] += rank[py];
        return true;
    }

};


class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {

        DSU dsu(n);
        int res = n;

        for(auto& edge : edges) {
            if(dsu.unionSet(edge[0], edge[1])) {
                res--;
            }
        }

        return res;

    }
};

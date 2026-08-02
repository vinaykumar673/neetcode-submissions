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

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) {
            return false;
        }

        if(px != py) {
            if(px < py) {
                parent[px] = py;
            }
            else if(px > py) {
                parent[py] = px;
            }
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
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

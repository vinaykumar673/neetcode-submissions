class UnionFind
{

public:
    vector<int> par;
    vector<int> rank;

    UnionFind(int n)
    {
        par.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }

    int Find(int n)
    {
        int curr = n;
        while(curr != par[curr])
        {
            par[curr] = par[par[curr]];
            curr = par[curr];
        }
        return curr;
    }

    bool Union(int n1, int n2)
    {
        int p1 = Find(n1);
        int p2 = Find(n2);

        if(p1 == p2)
        {
            return false;
        }

        if(rank[p1] > rank[p2])
        {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else
        {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        UnionFind dsu(n);
        int res = n;

        for(auto edge : edges)
        {
            if(dsu.Union(edge[0], edge[1]))
            {
                res--;
            }
        }

        return res;

    }
};

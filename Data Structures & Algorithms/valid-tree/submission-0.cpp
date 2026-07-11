class Solution {

    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        for(vector<int>& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(!dfs(0, -1))
        {
            return false;
        }

        return visited.size() == n;
    }

    bool dfs(int node, int prev)
    {
        if(visited.count(node))
        {
            return false;
        }

        visited.insert(node);

        for(auto& neigh : adj[node])
        {
            if(neigh == prev)
            {
                continue;
            }

            if(!dfs(neigh, node))
            {
                return false;
            }
        }

        return true;
    }
};


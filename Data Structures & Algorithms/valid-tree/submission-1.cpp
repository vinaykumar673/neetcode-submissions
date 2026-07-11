class Solution {

    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;
    queue<pair<int, int>> q;

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        for(vector<int>& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        q.push({0, -1});
        visited.insert(0);

        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            int node = p.first, prev = p.second;

            for(int neigh : adj[node])
            {
                if(neigh == prev)
                {
                    continue;
                }

                if(visited.count(neigh))
                {
                    return false;
                }

                visited.insert(neigh);
                q.push({neigh, node});
            }
        }

        return visited.size() == n;
    }
};


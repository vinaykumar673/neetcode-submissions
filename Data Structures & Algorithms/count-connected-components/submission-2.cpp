class Solution {
public:

    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {

        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for(auto& neigh : adj[curr]) {
                if(!visited[neigh]) {
                    q.push(neigh);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                components++;
                bfs(i, adj, visited);
            }
        }

        return components;

    }
};

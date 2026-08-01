class Solution {
public:

    bool hasCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {

        visited[node] = true;

        for(int neigh : adj[node]) {
            if(!visited[neigh]) {
                if(hasCycle(neigh, node, adj, visited)) {
                    return true;
                }
            }
            else if(neigh != parent) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int component = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                component++;
                if(hasCycle(i, -1, adj, visited)) {
                    return false;
                }
            }
        }

        return component == 1;

    }
};

class Solution {
public:

    bool hasCycle(int node, int parent, vector<vector<int>>& adj_list, vector<bool>& visited) {

        visited[node] = true;

        for(int neigh : adj_list[node]) {
            if(!visited[neigh]) {
                if(hasCycle(neigh, node, adj_list, visited)) {
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

        vector<vector<int>> adj_list(n);
        vector<bool> visited(n, false);
        for(auto& edge: edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                components++;
                if(hasCycle(i, -1, adj_list, visited)) {
                    return false;
                }
            }
        }

        return components == 1;

    }
};

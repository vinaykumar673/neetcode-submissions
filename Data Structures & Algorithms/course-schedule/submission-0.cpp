class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses);
        queue<int> q;
        vector<int> result;
        vector<vector<int>> adj(numCourses);

        for(auto& item : prerequisites) {
            adj[item[1]].push_back(item[0]);
        }

        for(auto& c : adj) {
            for(auto& cc : c) {
                indegree[cc]++;
            }
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

       
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for(auto& neigh : adj[curr]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return result.size() == numCourses;
        
    }
};

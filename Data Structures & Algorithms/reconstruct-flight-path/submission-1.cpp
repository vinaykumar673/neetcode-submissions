class Solution {

    unordered_map<string, vector<string>> adj;
    vector<string> res {"JFK"};
    int targetLen;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        targetLen = tickets.size() + 1;

        sort(tickets.begin(), tickets.end());

        for(vector<string>& edge : tickets)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        dfs("JFK");

        return res;
    }

    bool dfs(const string& src)
    {
        if(res.size() == targetLen)
        {
            return true;
        }

        if(adj.find(src) == adj.end())
        {
            return false;
        }

        vector<string> temp = adj[src];

        for(int i = 0; i < temp.size(); i++)
        {
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i);
            res.push_back(v);
            if(dfs(v))
            {
                return true;
            }
            adj[src].insert(adj[src].begin() + i, v);
            res.pop_back();
        }

        return false;
    }
};
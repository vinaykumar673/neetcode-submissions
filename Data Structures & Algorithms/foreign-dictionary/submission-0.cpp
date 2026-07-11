class Solution {

private:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string result;

public:
    string foreignDictionary(vector<string>& words) {

        for(auto word : words)
        {
            for(auto ch : word)
            {
                adj[ch];
            }
        }

        for(size_t i = 0; i < words.size() - 1; i++)
        {
            string w1 = words[i], w2 = words[i + 1];
            size_t minLen = min(w1.size(), w2.size());
            if(w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen))
            {
                return "";
            }
            
            for(size_t j = 0; j < minLen; j++)
            {
                if(w1[j] != w2[j])
                {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for(auto pair : adj)
        {
            if(dfs(pair.first))
            {
                return "";
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(char ch)
    {
        if(visited.count(ch))
        {
            return visited[ch];
        }

        visited[ch] = true;

        for(char neigh : adj[ch])
        {
            if(dfs(neigh))
            {
                return "";
            }
        }

        visited[ch] = false;
        result.push_back(ch);
        return false;
    }
};

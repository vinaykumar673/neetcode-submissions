class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        
        for(auto& word : words) {
            for(auto& ch : word) {
                adj[ch] = unordered_set<char>();
                indegree[ch] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int minLen = min(word1.size(), word2.size());

            if(word1.size() > word2.size() && word1.substr(0, minLen) == word2.substr(0, minLen)) {
                return "";
            }

            for(int j = 0; j < minLen; j++) {
                if(word1[j] != word2[j]) {
                    if(!adj[word1[j]].count(word2[j])) {
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        string res = "";
        for(auto& ct : indegree) {
            if(ct.second == 0) {
                q.push(ct.first);
            }
        }

        while(!q.empty()) {
            char curr = q.front();
            q.pop();
            res += curr;
            for(auto& neigh : adj[curr]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return res.size() == indegree.size() ? res : "";
    }
};

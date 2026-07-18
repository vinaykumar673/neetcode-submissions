class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> freq;

        for(auto s : strs) {
            vector<int> ct(26, 0);
            for(auto ch : s) {
                ct[ch - 'a']++;
            }
            string key = to_string(ct[0]);
            for(int i = 1; i < 26; i++) {
                key += "," + to_string(ct[i]);
            }
            freq[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto [k, v] : freq) {
            ans.push_back(v);
        }

        return ans;
        
    }
};

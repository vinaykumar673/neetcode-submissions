class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(const auto& n : nums) {
            freq[n]++;
        }

        vector<pair<int, int>> freq_pairs;

        for(const auto& p : freq) {
            freq_pairs.push_back({p.second, p.first});
        }

        sort(freq_pairs.begin(), freq_pairs.end(), greater<pair<int, int>>());

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(freq_pairs[i].second);
        }
    
        return ans;  
    }
};

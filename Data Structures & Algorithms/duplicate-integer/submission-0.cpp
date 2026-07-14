class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, int> freq;

        for(auto& n : nums)
        {
            freq[n]++;
        }

        for(auto& p : freq)
        {
            if(p.second > 1)
                return true;
        }

        return false;
        
    }
};
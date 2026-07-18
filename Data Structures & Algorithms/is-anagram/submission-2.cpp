class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> freqs;
        unordered_map<char, int> freqt;

        for(int i = 0; i < s.size(); i++)
        {
            freqs[s[i]]++;
            freqt[t[i]]++;
        }

        return freqs == freqt;
        
    }
};

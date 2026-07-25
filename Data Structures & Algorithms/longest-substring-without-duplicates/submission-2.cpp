class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s == "") return 0;

        unordered_set<char> seen;
        int max_len = 1, l = 0;
        seen.insert(s[l]);

        for(int r = 1; r < (int)s.size(); r++) {
            if(seen.count(s[r]) == 0) {
                max_len = max(max_len, r - l + 1);
            }
            else {
                while(seen.count(s[r]) > 0) {
                    seen.erase(s[l++]);
                }
            }
            seen.insert(s[r]);
        }
        
        return max_len;
    }
};

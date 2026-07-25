class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> chars(s.begin(), s.end());
        int res = 0;

        for(const auto& c : chars) {
            int l = 0, count = 0;
            for(int r = 0; r < s.size(); r++) {
                if(s[r] == c) {
                    count++;
                }
                else {
                    while((r - l + 1) - count > k) {
                        if(s[l] == c) count--;
                        l++;
                    }
                }
                res = max(res, r - l + 1);
            }
        }

        return res;
    }
};

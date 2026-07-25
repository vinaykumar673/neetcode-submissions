class Solution {
public:
    string minWindow(string s, string t) {

        if(t.empty()) return "";

        unordered_map<char, int> freqt, window;
        for(const auto& c : t) {
            freqt[c]++;
        }

        int have = 0, need = freqt.size();
        int res_len = INT_MAX;
        pair<int, int> res = {-1, -1};
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if(freqt.count(c) && window[c] == freqt[c]) {
                have++;
            }

            while(have == need) {
                if((r - l + 1) < res_len) {
                    res_len = (r - l + 1);
                    res = {l, r};
                }

                window[s[l]]--;

                if(freqt.count(s[l]) && window[s[l]] < freqt[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if(res_len == INT_MAX) return "";

        return s.substr(res.first, res_len);





    }
};

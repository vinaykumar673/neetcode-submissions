class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const auto& s : strs) {
            res.append(to_string(s.size()));
            res.append("#");
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            strs.push_back(s.substr(i, length));
            i = j;
        }
        return strs;
    }
};

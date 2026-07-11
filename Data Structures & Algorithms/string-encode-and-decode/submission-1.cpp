
class Solution {
public:

    string encode(vector<string>& strs) {

        string result = "";

        for(auto s : strs)
        {
            result += (to_string(s.size()) + '#' + s);
        }

        return result;

    }

    vector<string> decode(string s) {

        int i = 0, j = 0, len = 0;

        vector<string> ans;

        while(i < s.size())
        {
            j = i;

            while(s[j] != '#')
                j++;
            
            len = stoi(s.substr(i, j - i));

            string k = s.substr(j + 1, len);

            ans.push_back(k);

            i = j + 1 + len;
            
        }

        return ans;

    }
};

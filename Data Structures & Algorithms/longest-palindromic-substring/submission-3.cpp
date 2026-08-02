class Solution {
public:

    bool isPal(string s) {

        int l = 0, r = s.size() - 1;

        while(l <= r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    string longestPalindrome(string s) {

        string res = "";
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                string curr = s.substr(i, j - i + 1);
                if(isPal(curr)) {
                    if(curr.size() > res.size()) {
                        res = curr;
                    }
                }
            }
        }

        return res;
        
    }
};

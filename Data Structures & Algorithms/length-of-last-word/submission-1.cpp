class Solution {
public:
    int lengthOfLastWord(string s) {

        bool started = false;
        int start = 0, end = 0;

        for(int r = s.size() - 1; r >= 0; r--) {

            if(s[r] == ' ' && started == false) {
                continue;
            }
            else {
                if(started == false) {
                    started = true;
                    start = r;
                }
                else {
                    if(s[r] == ' ') {
                        end = r + 1;
                        break;
                    }
                }
            }
        }

        return (start - end + 1);
        
    }
};
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(const auto& ch : s) {
            if(st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                char curr = st.top();
                if(curr == '(' && ch == ')') {
                    st.pop();
                }
                else if(curr == '{' && ch == '}') {
                    st.pop();
                }
                else if(curr == '[' && ch == ']' ) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        if(st.empty()) return true;
        return false;
        
    }
};

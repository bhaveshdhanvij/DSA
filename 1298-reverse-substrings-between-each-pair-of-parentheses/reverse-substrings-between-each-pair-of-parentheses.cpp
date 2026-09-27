class Solution {
public:
    string reverseParentheses(string s) {
        string st = "" ;
        for ( char c : s ) {
            if ( c != ')' ) {
                st += c ;
            }else {
                string t = "" ;
                while (!st.empty() && st.back() != '(' ) {
                    t += st.back() ;
                    st.pop_back() ;
                }
                st.pop_back() ;
                st += t ;
            }
        }
        return st ;
    }
};
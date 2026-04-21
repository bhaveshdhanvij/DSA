class Solution {
public:
    string resultingString(string s) {
        stack<char> st ;
        for ( char c : s ) {
            if ( !st.empty() ) {
                char ch = st.top() ;
                
                char a = (c == 'z' ? 'a' : c + 1) ;
                char b = (c == 'a' ? 'z' : c - 1) ;

                if ( ch == a || ch == b ) {
                    st.pop() ;
                }else {
                    st.push(c) ;
                }
            }else {
                st.push(c) ;
            }
        }
        string ans = "" ;
        while (!st.empty()) {
            ans += st.top() ;
            st.pop() ;
        }

        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};
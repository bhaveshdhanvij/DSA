class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st ;
        for ( char c : s ) {
            if ( st.empty() ) st.push(c) ;
            else {
                char ch = st.top() ;
                if ( ch == c ) {
                    st.pop() ;
                }else {
                    st.push(c) ;
                }
            }
        }

        string a = "" ;
        while (!st.empty()) {
            a += st.top() ;
            st.pop() ;
        }
        reverse( a.begin() , a.end() ) ;
        return a ;
    }
};
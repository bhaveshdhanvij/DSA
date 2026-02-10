class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        
        for ( char c : s ) {
            if ( c == 'a' || c == 'b' ) st.push(c) ;
            else {
                if ( st.size() < 2 ) return false ;

                char x = st.top() ;
                st.pop() ;

                char y = st.top() ;
                st.pop() ;

                if ( x != 'b' || y != 'a' ) return false ;
            }
        }

        return st.empty() ;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;

        for ( char c : s ) {
            if ( c == 'a' || c == 'b' ) st.push(c) ;
            else {
                if ( st.size() < 2 ) return false ;

                char b = st.top() ; st.pop() ;
                char a = st.top() ; st.pop() ;

                if ( a != 'a' || b != 'b' ) return false ; 
            }
        }

        return st.empty() ;
    }
};
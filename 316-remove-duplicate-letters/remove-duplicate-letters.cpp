class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26 , 0) , f(26 , 0) ;
        for ( char c : s ) f[c - 'a']++ ;
        string st = "" ;
        for ( char c : s ) {
            int idx = c - 'a' ;
            if ( !vis[idx] ) {
                
                while ( !st.empty() && st.back() > c ) {
                    int topidx = st.back() - 'a' ;
                    if ( f[topidx] > 0 ) {
                        vis[topidx] = 0 ;
                        st.pop_back() ;
                    }else {
                        break ;
                    }
                }

                vis[idx] = 1 ;
                st.push_back(c) ;
            }

            f[idx]-- ;
        }

        return st ;
    }
};
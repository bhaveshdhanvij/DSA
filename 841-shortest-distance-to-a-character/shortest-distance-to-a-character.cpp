class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> t ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == c ) t.push_back(i) ;
        }

        int n = s.size() ;
        vector<int> ans(n) ;
        for ( int i = 0 ; i < n ; i++ ) {
            int m = INT_MAX ;
            for ( int x : t ) {
                m = min ( m , abs(x - i) ) ;
            }
            ans[i] = m ;
        }

        return ans ;
    }
};
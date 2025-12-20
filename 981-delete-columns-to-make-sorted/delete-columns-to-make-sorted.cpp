class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s[0].size() ;
        int m = s.size() ;
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            string t = "" ;
            for ( int j = 0 ; j < m ; j++ ) {
                t += s[j][i] ;
            }
            string rev = t ;
            sort ( rev.begin() , rev.end() ) ;
            if ( t != rev ) ans++ ;
        }
        return ans ;
    }
};
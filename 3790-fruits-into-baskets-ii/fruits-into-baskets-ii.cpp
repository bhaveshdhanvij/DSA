class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size() ;
        vector<bool> vis ( n , false ) ;

        for ( int i = 0 ; i < n ; i++ ) {

            for ( int j = 0 ; j < n ; j++ ) {
                if ( vis[j] ) continue ;

                if ( f[i] <= b[j] ) {
                    vis[j] = true ;
                    break ;
                }
            }
        }

        int ans = 0 ;
        for ( auto p : vis ) {
            if ( !p ) ans++ ;
        }
        return ans ;
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& a) {
        int m = a.size() , n = a[0].size() ;
        vector<vector<bitset<1024>>> dp(m , vector<bitset<1024>>(n)) ;
        dp[0][0][a[0][0]] = 1 ;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( i == 0 && j == 0 ) continue ;
                bitset<1024> p ;
                if ( i > 0 ) {
                    p |= dp[i - 1][j] ;
                }

                if ( j > 0 ) {
                    p |= dp[i][j - 1] ;
                }

                int x = a[i][j] ;
                for ( int t = 0 ; t < 1024 ; t++ ) {
                    if ( p[t] ) {
                        dp[i][j][t ^ x] = 1 ;
                    }
                }
            }
        }

        for ( int x = 0 ; x < 1024 ; x++ ) {
            if ( dp[m - 1][n - 1][x] ) return x ;
        }

        return 0 ;
    }
};

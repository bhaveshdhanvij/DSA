class Solution {
public:
    int minDistance(string a, string b) {
        // TC : O(N * M) , SC : O(N * M)
        int n = a.size() , m = b.size() ;
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1)) ;
        // dp[i][j] will store min op to convert first i chars of a to first j chars of b 
        for ( int i = 0 ; i <= n ; i++ ) {
            dp[i][0] = i ; // delete 
        }

        for ( int j = 0 ; j <= m ; j++ ) {
            dp[0][j] = j ; // insert 
        }

        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= m ; j++ ) {
                if ( a[i - 1] == b[j - 1] ) {
                    dp[i][j] = dp[i - 1][j - 1] ;
                }else {
                    dp[i][j] = 1 + min ({ dp[i - 1][j] , dp[i][j - 1] , dp[i - 1][j - 1]}) ;
                }
            }
        }

        return dp[n][m] ;
    }
};
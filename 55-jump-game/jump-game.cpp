class Solution {
public:
    bool canJump(vector<int>& a) {
        // DP : Tabulation : top - bottom 

        int n = a.size() ;
        vector<bool> dp(n , false) ;

        dp[n - 1] = true ;

        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            for ( int j = 1 ; j <= a[i] && i + j < n ; j++ ) {
                if ( dp[i + j] ) {
                    dp[i] = true ;
                    break ;
                }
            }
        }

        return dp[0] ;
    }
};
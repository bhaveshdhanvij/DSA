class Solution {
public:
    long long rob(vector<int>& a, vector<int>& c) {
        int n = a.size() ;
        if ( n == 1 ) return a[0] ;

        vector<long long> dp(n , 0) ;
        dp[0] = a[0] ;

        if ( c[1] == c[0] ) {
            dp[1] = max ( a[0] , a[1] ) ;
        }else {
            dp[1] = a[0] + a[1] ;
        }

        for ( int i = 2 ; i < n ; i++ ) {
            if ( c[i] == c[i - 1] ) {
                dp[i] = max ( dp[i - 1] , dp[i - 2] + a[i] ) ;
            }else {
                dp[i] += dp[i - 1] + a[i] ;
            }
        }

        return dp[n - 1] ;
    }
};
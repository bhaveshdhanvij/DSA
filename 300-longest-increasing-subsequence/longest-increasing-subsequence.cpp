class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        // Approach 1 : brute force check every sub. and check if that is increasing or not  
        // TC : O(2**N * N)

        // Optimal Approach : Memoization DP 
        // dp[i] = will store maximum sub. length ending at a[i] 
        // TC : O(N**2) SC : O(N)

        int n = a.size() ;
        vector<int> dp(n , 1) ;

        for ( int i = 1 ; i < n ; i++ ) {
            for ( int j = 0 ; j < i ; j++ ) {
                if ( a[i] > a[j] ) {
                    dp[i] = max ( dp[i] , dp[j] + 1 ) ;
                }
            }
        }

        int ans = 1 ;
        for ( int x : dp ) ans = max ( ans , x ) ;
        
        return ans ;
    }
};
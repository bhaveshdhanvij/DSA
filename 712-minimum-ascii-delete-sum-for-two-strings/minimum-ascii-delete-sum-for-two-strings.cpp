class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        // TC : O(N * M) , SC : O(N * M) 
        // Optimal Approach : Contradiction : try to maximize strings with max ASCII value 

        int n = s.size() , m = t.size() ;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1 , 0)) ;

        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= m ; j++ ) {
                if ( s[i - 1] == t[j - 1] ) {
                    dp[i][j] = dp[i - 1][j - 1] + s[i - 1] ;
                }else {
                    dp[i][j] = max ( dp[i - 1][j] , dp[i][j - 1] ) ;
                }
            }
        } 

        int a = 0 , b = 0 ;
        for ( char c : s ) a += c ;
        for ( char c : t ) b += c ;

        return a + b - 2 * dp[n][m] ; // since dp[n][m] will be for indivisual string 
    }
};
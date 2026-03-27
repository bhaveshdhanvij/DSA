class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<bool>> dp(n , vector<bool>(n , false)) ;
        // dp[i][j] will store whether we can reach j from i 
        for ( auto a : p ) {
            dp[a[0]][a[1]] = true ;
        }

        for ( int k = 0 ; k < n ; k++ ) {
            for ( int i = 0 ; i < n ; i++ ) {
                for ( int j = 0 ; j < n ; j++ ) {
                    if ( dp[i][k] && dp[k][j] ) {
                        dp[i][j] = true ;
                    }
                }
            }
        }

        vector<bool> ans ;
        for ( auto x : q ) {
            ans.push_back(dp[x[0]][x[1]]) ;
        }

        return ans ;
    }
};
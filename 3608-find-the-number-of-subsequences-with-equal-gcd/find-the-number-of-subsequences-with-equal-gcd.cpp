class Solution {
public:
    static const int mod = 1000000007 ;

    int subsequencePairCount(vector<int>& a) {
        int maxx = *max_element(a.begin(), a.end()) ;

        vector<vector<int>> dp(maxx + 1, vector<int>(maxx + 1)) ;
        dp[0][0] = 1 ;

        for (int x : a) {
            auto t = dp ;

            for ( int i = 0 ; i <= maxx ; i++ ) {
                for ( int j = 0 ; j <= maxx ; j++ ) {
                    if (!dp[i][j]) continue ;

                    int u = gcd(i, x) ;
                    t[u][j] = (t[u][j] + dp[i][j]) % mod ;

                    int v = gcd(j, x) ;
                    t[i][v] = (t[i][v] + dp[i][j]) % mod ;
                }
            }

            dp.swap(t) ;
        }

        long long ans = 0 ;
        for ( int i = 1 ; i <= maxx ; i++ ) ans = (ans + dp[i][i]) % mod ;

        return ans ;
    }
};
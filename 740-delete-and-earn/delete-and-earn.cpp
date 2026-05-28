class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int maxx = *max_element(a.begin() , a.end()) ;

        vector<int> p(maxx + 1 , 0) ;
        for ( int x : a ) p[x] += x ;

        vector<int> dp(maxx + 1 , 0) ;

        dp[0] = 0 ;
        dp[1] = p[1] ;

        for ( int i = 2 ; i <= maxx ; i++ ) {
            int take = p[i] + dp[i - 2] ;
            int skip = dp[i - 1] ;
            
            dp[i] = max ( take , skip ) ;
        }
        
        return dp[maxx] ;
    }
};
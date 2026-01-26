class Solution {
private:
    int helper( vector<int> a ) {
        int n = a.size() ;

        if ( n == 0 ) return 0 ;
        if ( n == 1 ) return a[0] ;

        vector<int> dp(n , 0) ;

        dp[0] = a[0] ;
        dp[1] = max ( a[0] , a[1] ) ;

        for ( int i = 2 ; i < n ; i++ ) {
            dp[i] = max ( dp[i - 1] , dp[i - 2] + a[i] ) ;
        }

        return dp[n - 1] ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;

        if ( n == 0 ) return 0 ;
        if ( n == 1 ) return nums[0] ;

        vector<int> a ( nums.begin() + 1 , nums.end() ) ;
        vector<int> b ( nums.begin() , nums.end() - 1 ) ;

        int ans1 = helper(a) ;
        int ans2 = helper(b) ;

        return max( ans1 , ans2 ) ;
    }
};
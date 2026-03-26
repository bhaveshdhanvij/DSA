class Solution {
public:
    bool f( int idx , int target , vector<int>& a , vector<vector<int>>& dp ) {
        if ( target == 0 ) return true ;
        if ( idx == 0 ) return a[0] == target ;

        if ( dp[idx][target] != -1 ) return dp[idx][target] ;

        bool notTake = f(idx - 1 , target , a , dp) ;
        bool take = false ;

        if ( a[idx] <= target ) {
            take = f(idx - 1 , target - a[idx] , a , dp ) ;
        }

        return dp[idx][target] = take || notTake ;
    }
    bool canPartition(vector<int>& a ) {
        int n = a.size() ;
        int sum = 0 ;

        for ( int x : a ) sum += x ;

        if ( sum % 2 ) return false ;

        int t = sum / 2 ;
        vector<vector<int>> dp(n , vector<int>( t + 1 , -1)) ;
        return f(n - 1 , t , a , dp ) ;
    }
};
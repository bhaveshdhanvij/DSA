class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size() ;
        int total = 0 ;

        for ( int x : a ) total += x ;

        if ( k == n ) return total ;
        
        int w = n - k ;
        int ans = 0 ;

        int l = 0 , sum = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            sum += a[r] ;
            
            if ( r - l + 1 == w ) {
                ans = max ( ans , total - sum ) ;
                sum -= a[l] ;
                l++ ;
            }
        }

        return ans  ;
    }
};
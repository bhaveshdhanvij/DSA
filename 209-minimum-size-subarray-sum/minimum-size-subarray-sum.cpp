class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int ans = INT_MAX ;
        int n = a.size() ;

        int curr = 0 , l = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            curr += a[r] ;
            while ( curr >= t ) {
                ans = min ( ans , r - l + 1 ) ;
                curr -= a[l] ;
                l++ ;
            }
        }

        return ans == INT_MAX ? 0 : ans ;
    }
};
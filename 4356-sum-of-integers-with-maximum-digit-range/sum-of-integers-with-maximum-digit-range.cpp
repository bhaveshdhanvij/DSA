class Solution {
public:
    int helper(int n) {
        int maxx = -1 , minn = 10 ;
        while( n > 0 ) {
            int r = n % 10 ;
            maxx = max ( maxx , r ) ;
            minn = min ( minn , r ) ;
            n /= 10 ;
        }
        return maxx - minn ;
    }
    int maxDigitRange(vector<int>& a) {
        int n = a.size() ;
        vector<int> t(n) ;
        int maxx = INT_MIN ;
        for ( int i = 0 ; i < n ; i++ ) {
            int val = helper(a[i]) ;
            t[i] = val ;
            maxx = max ( maxx , val ) ;
        }
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( t[i] == maxx ) ans += a[i] ;
        }
        return ans ;
    }
};
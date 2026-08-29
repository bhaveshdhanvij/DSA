class Solution {
public:
    long long maximumProduct(vector<int>& a, int m) {
        int n = a.size() ;
        vector<int> minn(n) , maxx(n) ;
        minn[n - 1] = maxx[n - 1] = a[n - 1] ;
        
        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            minn[i] = min(minn[i + 1] , a[i] ) ;
            maxx[i] = max(maxx[i + 1] , a[i] ) ;
        }

        long long ans = LLONG_MIN ;
        for ( int i = 0 ; i + m - 1 < n ; i++ ) {
            int j = i + m - 1 ;
            ans = max ( ans , 1LL * a[i] * minn[j] ) ;
            ans = max ( ans , 1LL * a[i] * maxx[j] ) ;
        }

        return ans ;
    }
};
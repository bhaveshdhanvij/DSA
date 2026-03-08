class Solution {
public:
    int smallestBalancedIndex(vector<int>& a) {
        int n = a.size() ;
        vector<long long> r(n + 1 , 1) ;

        const long long l = 1e15 ;

        for ( int i = n - 1 ; i >= 0 ; i-- ) {
            if ( r[i + 1] > l / a[i] ) r[i] = l ;
            else r[i] = r[i + 1] * a[i] ;
        }

        long long curr = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            long long p = r[i + 1] ;
            
            if ( curr == p ) return i ;

            curr += a[i] ;
        }

        return -1 ;
    }
};
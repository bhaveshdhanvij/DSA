class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& a, int k) {
        int n = a.size() ;
        sort ( a.begin() , a.end() ) ;
        
        long long op = 0 ;
        int mid = n / 2 ;
        
        op += abs(a[mid] - k) ;

        for ( int i = 0 ; i < mid ; i++ ) {
            if ( a[i] > k ) {
                op += a[i] - k ;
            }
        }

        for ( int i = mid + 1 ; i <= n - 1 ; i++ ) {
            if ( a[i] < k ) {
                op += k - a[i] ;
            }
        }

        return op ;
    }
};
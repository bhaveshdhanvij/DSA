class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        int n  = a.size() ;
        long long ans = 0 ;
        sort ( a.rbegin() , a.rend() ) ;
        int t = 0 ;
        for ( int i = 0 ; i < n && k > 0 ; i++ ) {
            if ( i != 0 ) {
                a[i] = max ( 0 , a[i] - t ) ;
            }
            ans += a[i] ;
            t++ ;
            k-- ;
        }
        return ans ;
    }
};
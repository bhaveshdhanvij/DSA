 class Solution {
public:
    long long maximumTotalSum(vector<int>& a) {
        sort ( a.rbegin() , a.rend() ) ;
        
        long long prev = a[0] , ans = a[0] ;

        for ( int i = 1 ; i < a.size() ; i++ ) {
            long long curr = min ( (long long)a[i] , prev - 1 ) ;

            if ( curr <= 0 ) return -1 ;

            ans += curr ;
            prev = curr ;
        }

        return ans ;
    }
};
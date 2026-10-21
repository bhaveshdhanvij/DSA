class Solution {
public:
    bool canSortArray(vector<int>& a) {
        int n = a.size() ;
        int p = 0 , i = 0 ;
        while ( i < n ) {
            int b = __builtin_popcount(a[i]) ;
            int minn = a[i] , maxx = a[i] ;
            while ( i < n && __builtin_popcount(a[i]) == b) {
                minn = min ( minn , a[i] ) ;
                maxx = max ( maxx , a[i] ) ;
                i++ ;
            }
            if ( p > minn ) return false ;
            p = maxx ;
        }
        return true ;
    }
};
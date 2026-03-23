class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int n = a.size() ;
        int even = 0 , odd = 0 , minn = INT_MAX ;

        for ( int x : a ) {
            if ( x % 2 == 0 ) even++ ;
            else {
                minn = min ( minn , x ) ;
                odd++ ;
            }
        }

        if ( even == n || odd == n ) return true ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( a[i] % 2 == 0 ) {
                if ( a[i] - minn <= 0 ) return false ;
            }
        }

        return true ;
    }
};
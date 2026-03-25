class Solution {
public:
    bool helper( int n ) {
        if ( n <= 1 ) return false ;
        for ( int i = 2 ; i * i <= n ; i++ ) {
            if ( n % i == 0 ) {
                return false ;
            }
        }
        return true ;
    }
    long long splitArray(vector<int>& a) {
        long long x = 0 , y = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( helper(i) ) x += a[i] ;
            else y += a[i] ;
        }

        return abs(x - y) ;
    }
};
class Solution {
public:
    string convertToBase7(int n) {
        if ( n == 0 ) return "0" ;
        bool neg = false ;
        
        if ( n < 0 ) {
            neg = true ;
            n = -n ;
        }

        string ans = "" ;
        while ( n ) {
            int r = n % 7 ;
            ans += (r + '0') ;
            n /= 7 ;
        }

        if ( neg ) ans += '-' ;
        reverse( ans.begin() , ans.end() ) ;
        return ans ;
    }
};
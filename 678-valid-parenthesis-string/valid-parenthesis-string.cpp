class Solution {
public:
    bool checkValidString(string s) {
        int l = 0 , h = 0 ;
        for ( char c : s ) {
            if ( c == '(' ) {
                l++ , h++ ;
            }else if ( c == ')' ) {
                l-- , h-- ;
            }else {
                l-- ;
                h++ ;
            }
            if ( h < 0 ) return false ;
            l = max(0 , l) ;
        }
        return l == 0 ;
    }
};
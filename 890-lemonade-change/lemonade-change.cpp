class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0 , t = 0 , tw = 0 ;
        for ( int x : bills ) {
            if ( x == 5 ) {
                f++ ;
            }else if ( x == 10 ) {
                t++ ;
                if ( f == 0 ) return false ;
                f-- ;
            }else {
                tw++ ;
                if ( f == 0 || (t == 0 && f < 3) ) return false ;
                if ( t > 0 ) {
                    t-- ;
                    f-- ;
                }else {
                    f -= 3 ;
                }
            }
        }
        return true ;
    }
};
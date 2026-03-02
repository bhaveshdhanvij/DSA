class Solution {
public:
    bool sumOfNumberAndReverse(int num) {

        if ( num == 0 ) return true ;
        for ( int i = 1 ; i <= num ; i++ ) {
            string s = to_string(i) ;
            string rev = s ;
            reverse(rev.begin() , rev.end() ) ;

            if ( stoi(s) + stoi(rev) == num ) return true ;
        }

        return false ;
    }
};
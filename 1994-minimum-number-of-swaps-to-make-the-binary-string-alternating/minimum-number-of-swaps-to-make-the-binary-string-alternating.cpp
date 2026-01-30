class Solution {
public:
    int minSwaps(string s) {
        int one = 0 , zero = 0 , mz = 0 , mo = 0 ;

        for ( char c : s ) {
            if ( c == '0' ) zero++ ;
            else one++ ;
        }

        if ( abs(one - zero) > 1 ) return -1 ;

        for ( int i = 0 ; i < s.size() ; i += 2 ) {
            if ( s[i] != '0' ) mz++ ;
            else mo++ ;
        }

        return zero == one ? min( mz , mo ) : one > zero ? mo : mz ;
    }
};
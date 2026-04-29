class Solution {
public:
    bool helper( char c ) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
    }
    bool isValid(string s) {
        bool c = false , v = false ;
        for ( char ch : s ) {
            if ( !isalnum((unsigned char)ch) ) return false ;
            ch = tolower((unsigned char)ch) ;

            if ( ch >= '0' && ch <= '9' ) continue ;
            if ( helper(ch) ) v = true ;
            else  c = true ;
        }

        return c && v && s.size() >= 3 ;
    }
};
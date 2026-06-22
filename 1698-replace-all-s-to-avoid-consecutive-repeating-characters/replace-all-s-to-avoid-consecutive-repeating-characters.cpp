class Solution {
public:
    string modifyString(string s) {
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == '?' ) {
                char prev = '_' , next = '_' ;
                if ( i - 1 >= 0 ) prev = s[i - 1] ;
                if ( i + 1 < s.size() ) next = s[i + 1] ;
                
                char c = '_' ;
                for ( c = 'a' ; c <= 'z' ; c++ ) {
                    if ( c != prev && c != next ) {
                        break ;
                    }
                }
                s[i] = c ;
            }
        }
        return s ;
    }
};
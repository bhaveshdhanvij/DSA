class Solution {
public:
    bool isNumber(string s) {
        bool dig = false , dot = false , exp = false , dexp = true ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            char c = s[i] ;
            if ( isdigit(c) ) {
                dig = true ;
                if ( exp ) {
                    dexp = true ;
                }
            }else if ( c == '+' || c == '-' ) {
                if ( i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E' ) {
                    return false ;
                }
            }else if ( c == '.' ) {
                if ( dot || exp ) {
                    return false ;
                }
                dot = true ;
            }else if ( c == 'e' || c == 'E' ) {
                if ( exp || !dig ) {
                    return false ;
                }
                exp = true ;
                dexp = false ;  
            } else return false ;
        }

        return dig && dexp ;
    }
};
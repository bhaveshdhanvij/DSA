class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num) ;

        string maxx = s , minn = s ;
        
        int i = 0 ;
        while ( i < s.size() && s[i] == '9' ) i++ ;

        if ( i != s.size() ) {
            char t = s[i] ;
            for ( char &c : maxx ) {
                if ( c == t ) {
                    c = '9' ;
                }
            }
        }

        i = 0 ;
        while ( i < s.size() && s[i] == '0' ) i++ ;

        if ( i != s.size() ) {
            char t = s[i] ;
            for ( char &c : minn ) {
                if ( c == t ) {
                    c = '0' ;
                }
            }
        }

        return stoi(maxx) - stoi(minn) ;
    }
};
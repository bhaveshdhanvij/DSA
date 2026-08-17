class Solution {
public:
    int vowelConsonantScore(string s) {
        int c = 0 , v = 0 ;
        for ( char ch : s ) {
            if ( ch >= '0' && ch <= '9' ) continue ;
            if ( ch == ' ' ) continue ;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) v++;
            else c++ ;
        }
        if ( c > 0 ) return (v / c) ;
        return 0 ;
    }
};
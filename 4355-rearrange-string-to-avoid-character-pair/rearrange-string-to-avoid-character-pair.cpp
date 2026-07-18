class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int a = 0 , b = 0 ;
        string ans = "" ;
        for ( char c : s ) {
            if ( c == x ) a++ ;
            else if ( c == y ) b++ ;
        }
        while (b--) ans += y ;
        while (a--) ans += x ;
        for ( char c : s ) {
            if ( c != x && c != y ) {
                ans += c ;
            }
        }
        return ans ;
    } 
};
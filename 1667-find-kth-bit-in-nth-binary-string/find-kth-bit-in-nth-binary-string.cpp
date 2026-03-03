class Solution {
public:
    string f1(string s) {
        string ans = "" ;
        for ( char c : s ) {
            if ( c == '0' ) ans += '1' ;
            else ans += '0' ;
        }
        return ans ;
    }

    string f2(string s) {
        reverse(s.begin() , s.end() ) ;
        return s ;
    }
    char findKthBit(int n, int k) {
        string s = "0" ;
        for ( int i = 1 ; i <= n - 1 ; i++ ) {
            string a = s + "1" + f2(f1(s)) ;
            s = a ;
        }

        return s[k - 1] ;
    }
};
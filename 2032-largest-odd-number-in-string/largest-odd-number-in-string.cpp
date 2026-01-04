class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size() ;
        int i = n - 1 ;
        while ( i >= 0 && (s[i] - '0') % 2 == 0 ) {
            i-- ;
        }
        if ( i == -1 ) return "" ;
        return s.substr(0 , i + 1) ;
    }
};
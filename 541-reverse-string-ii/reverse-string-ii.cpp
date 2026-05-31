class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length() ;
        int i = 0 ;
        while ( i < n ) {
            int size = min ( n - i , k ) ;
            reverse(s.begin() + i , s.begin() + i + size ) ;
            i += 2 * k ;
        }
        return s ;
    }
};
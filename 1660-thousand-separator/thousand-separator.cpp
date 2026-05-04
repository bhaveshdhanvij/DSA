class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n) ;
        string ans = "" ;
        int curr = 0 ;
        for ( int i = s.size() - 1 ; i >= 0 ; i-- ) {
            ans = s[i] + ans ;
            curr++ ;
            if ( curr == 3 && i != 0 ) {
                ans = '.' + ans ;
                curr = 0 ;
            }
        }
        return ans ;
    }
};
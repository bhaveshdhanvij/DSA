class Solution {
public:
    string helper( string &s , int &i ) {
        string ans = "" ;
        int num = 0 ;
        while ( i < s.size() ) {
            if ( isdigit(s[i]) ) {
                num = num * 10 + (s[i] - '0') ;
            }else if ( s[i] == '[') {
                i++ ;
                string inner = helper(s , i) ;
                while ( num-- ) ans += inner ;
                num = 0 ;
            }else if ( s[i] == ']' ) {
                return ans ;
            }else {
                ans += s[i] ;
            }
            i++ ;
        }
        return ans ;
    }
    string decodeString(string s) {
        int i = 0 ;
        return helper(s , i) ;
    }
};
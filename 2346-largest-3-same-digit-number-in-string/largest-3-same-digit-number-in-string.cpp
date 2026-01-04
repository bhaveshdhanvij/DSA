class Solution {
public:
    string largestGoodInteger(string s) {
        string ans = "" ;
        int n = s.size() ;
        for ( int i = 2 ; i < n ; i++ ) {
            if ( s[i] == s[i - 1] && s[i] == s[i - 2] ) {
                ans = max ( ans , s.substr(i - 2 , 3)) ;
            }
        }
        return ans ;
    }
};
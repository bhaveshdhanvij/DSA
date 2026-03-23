class Solution {
public:
    string compressedString(string s) {
        int n = s.size() ;
        int idx = 0 , i = 0 ;
        string ans = "" ;
        while ( i < n ) {
            int curr = s[i] ;
            int count = 0 ;
            while ( i < n && curr == s[i] ) {
                i++ ;
                count++ ;
            }
            while ( count ) {
                int cnt = min ( 9 , count ) ;
                ans += to_string(cnt) ;
                ans += curr ;
                count -= cnt ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int ans = 0 , curr = 1 , uni = 1 ;
        for ( int i = 1 ; i < s.size() ; i++ ) {
            if ( s[i - 1] <= s[i] ) {
                curr++ ;
                if ( s[i - 1] < s[i] ) {
                    uni++ ;
                }
            }else {
                curr = 1 ;
                uni = 1 ;
            }

            if ( uni == 5 ) {
                ans = max ( ans , curr ) ;
            }
        }

        return ans ;
    }
};
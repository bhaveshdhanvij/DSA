class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0 ;
        long long i = 0 ;
        for ( long long j = 0 ; j < s.size() ; j++ ) {
            if ( s[j] == '0' ) {
                ans += j - i ;
                i++ ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> f(26 , -1) , l(26 , -1) ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            int idx ;
            if ( s[i] >= 'a' && s[i] <= 'z' ) {
                idx = s[i] - 'a' ;
                l[idx] = i ;
            }else {
                idx = s[i] - 'A' ;
                if ( f[idx] == -1 ) {
                    f[idx] = i ;
                }
            }
        } 
        int ans = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( l[i] != -1 && f[i] != -1 && l[i] < f[i] ) {
                ans++ ;
            }
        }
        return ans ;
    }
};
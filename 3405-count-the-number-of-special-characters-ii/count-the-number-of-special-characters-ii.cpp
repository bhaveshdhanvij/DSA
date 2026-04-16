class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> first(26 , -1) , last(26 , -1) ;
        int n = s.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            int idx = -1 ;
            if ( s[i] >= 'a' && s[i] <= 'z' ) {
                idx = s[i] - 'a' ;
                last[idx] = i ;
            }else {
                idx = s[i] - 'A' ;
                if ( first[idx] == -1 ) {
                    first[idx] = i ;
                }
            }
        }

        int ans = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( first[i] != -1 && last[i] != -1 && last[i] < first[i] ) {
                ans++ ;
            }
        }

        return ans ;
    }
};
class Solution {
public:
    int bestClosingTime(string a) {
        int n = a.size() ;
        vector<int> p(n + 1 , 0) , s(n + 1 , 0) ;
        int N = 0 ;
        for ( int i = 0 ; i <= n ; i++ ) {
            p[i] = N ;
            if ( i < n && a[i] == 'N' ) N++ ;
        }
        int Y = 0 ;
        for ( char c : s ) {
            if ( c == 'Y' ) Y++ ;
        }
        for ( int i = 0 ; i <= n ; i++ ) {
            s[i] = Y ;
            if ( i < n && a[i] == 'Y' ) Y-- ;
        }
        int best = INT_MAX , ans = 0 ;
        for ( int i = 0 ; i <= n ; i++ ) {
            if ( best > p[i] + s[i] ) {
                best = p[i] + s[i] ;
                ans = i ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length() ;
        int count[3] = {} ;
        for ( char c : s ) count[c - 'a']++ ;
        for ( int i = 0 ; i < 3 ; i++ ) {
            count[i] -= k ;
            if ( count[i] < 0 ) return -1 ;
        }
        if ( k == 0 ) return 0 ;
        int maxx = 0 , l = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            count[s[r] - 'a']-- ;
            while ( count[0] < 0 || count[1] < 0 || count[2] < 0 ) {
                count[s[l] - 'a']++ ;
                l++ ;
            }
            maxx = max ( maxx , r - l + 1 ) ;
        }
        return n - maxx ;
    }
};
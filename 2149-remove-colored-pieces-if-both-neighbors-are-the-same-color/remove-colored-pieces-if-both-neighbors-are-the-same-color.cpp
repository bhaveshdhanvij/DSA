class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size() , a = 0 , b = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( i + 1 < n && i + 2 < n && s[i] == 'A' && s[i + 1] == 'A' && s[i + 2] == 'A' ) {
                a++ ;
            }
            if ( i + 1 < n && i + 2 < n && s[i] == 'B' && s[i + 1] == 'B' && s[i + 2] == 'B' ) {
                b++ ;
            }
        }

        return a > b ;
    }
};
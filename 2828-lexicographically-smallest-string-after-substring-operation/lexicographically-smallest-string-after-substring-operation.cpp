class Solution {
public:
    string smallestString(string s) {
        int n = s.size() ;
        int j = 0 ;
        while ( j < n && s[j] == 'a' ) j++ ;

        if ( j == n ) {
            s[n - 1] = 'z' ;
            return s ;
        }

        for ( int i = j ; i < n && s[i] != 'a' ; i++ ) {
            s[i] = s[i] - 1 ;
        }

        return s ;
    }
};
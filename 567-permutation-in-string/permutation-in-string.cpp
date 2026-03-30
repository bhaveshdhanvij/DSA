class Solution {
public:
    bool checkInclusion(string s, string t) {
        vector<int> a(26 , 0) , b(26 , 0) ;
        for ( char c : s ) a[c - 'a']++ ;
        
        int l = 0 ;
        for ( int r = 0 ; r < t.size() ; r++ ) {
            b[t[r] - 'a']++ ;
            if ( r - l + 1 == s.size() ) {
                if ( a == b ) return true ;
                b[t[l] - 'a']-- ;
                l++ ;
            }
        }
        return false ;
    }
};
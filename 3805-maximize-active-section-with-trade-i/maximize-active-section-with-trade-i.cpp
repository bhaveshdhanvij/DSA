class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length() ;
        int one = 0 , maxx = 0 , pz = INT_MIN ;
        int i = 0 ; 
        while ( i < n ) {
            int j = i ;
            while ( j < n && s[j] == s[i] ) j++ ;
            int l = j - i ;

            if ( s[i] == '1' ) {
                one += l ;
            }else {
                maxx = max ( maxx , pz + l ) ;
                pz = l ;
            }
            i = j ;
        }
        return maxx + one ;
    }
};
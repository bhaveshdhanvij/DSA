class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        int s = 0 , ans = 0 ;
        sort(t.begin() , t.end()) ;
        int i = 0 , j = t.size() - 1 ;
        while ( i <= j ) {
            if ( p >= t[i] ) {
                p -= t[i++] ;
                s++ ;
                ans = max ( ans , s ) ;
            }else if ( s > 0 ) {
                p += t[j--] ;
                s-- ;
            }else break ;
        }

        return ans ;
    }
};
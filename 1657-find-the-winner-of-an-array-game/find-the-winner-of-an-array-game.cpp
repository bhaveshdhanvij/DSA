class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int w = a[0] , c = 0 ;
        for ( int i = 1 ; i < a.size() ; i++ ) {
            if ( w > a[i] ) {
                c++ ;
            }else {
                w = a[i] ;
                c = 1 ;
            }
            if ( c == k ) return w ;
        }
        return w ;
    }
};
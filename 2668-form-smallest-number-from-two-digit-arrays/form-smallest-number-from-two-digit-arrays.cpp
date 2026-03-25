class Solution {
public:
    int minNumber(vector<int>& a, vector<int>& b) {
        map<int,int> x , y ;

        int d1 = 10 , d2 = 10 ;

        for ( int i : a ) {
            d1 = min ( d1 , i ) ;
            x[i]++ ;
        }
        for ( int i : b ) {
            d2 = min ( d2 , i ) ;
            y[i]++ ;
        }

        for ( auto p : x ) {
            if ( y.count(p.first) ) return p.first ;
        }

        return min ( d1 , d2 ) * 10 + max(d1 , d2 ) ;
    }
};
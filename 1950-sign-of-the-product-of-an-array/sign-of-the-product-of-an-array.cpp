class Solution {
public:
    int arraySign(vector<int>& a) {
        int c = 0 ;
        for ( int x : a ) {
            if ( x == 0 ) return 0 ;
            else if ( x < 0 ) c++ ;
        }

        return c % 2 == 0 ? 1 : -1 ;
    }
};
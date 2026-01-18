class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int e = 0 , o = 0 ;

        for ( int x : position ) {
            if ( x % 2 == 0 ) e++ ;
            else o++ ;
        }

        return min( e , o ) ;
    }
};
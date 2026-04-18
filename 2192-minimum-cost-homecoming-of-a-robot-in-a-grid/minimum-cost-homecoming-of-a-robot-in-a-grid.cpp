class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int i = startPos[0] , j = startPos[1] ;
        int gi = homePos[0] , gj = homePos[1] ;

        int ans = 0 ;
        while ( i < gi ) ans += rowCosts[++i] ;
        while ( i > gi ) ans += rowCosts[--i] ;

        while ( j < gj ) ans += colCosts[++j] ;
        while ( j > gj ) ans += colCosts[--j] ;

        return ans ;
    }
};
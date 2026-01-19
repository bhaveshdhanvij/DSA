class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0 ;

        for ( int x : cost ) ans += x ;

        sort ( cost.rbegin() , cost.rend() ) ;

        for ( int i = 2 ; i < cost.size() ; i += 3 ) {
            ans -= cost[i] ;
        }

        return ans ;    
    }
};
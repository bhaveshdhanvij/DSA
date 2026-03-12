class Solution {
public:
    int maxProfit(vector<int>& a) {
        int minn = INT_MAX ;
        int ans = 0 ;
        for ( int x : a ) {
            minn = min ( minn , x ) ;
            ans = max ( ans , x - minn) ;
        }

        return ans ;
    }
};
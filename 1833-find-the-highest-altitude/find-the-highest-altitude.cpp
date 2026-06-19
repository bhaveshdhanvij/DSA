class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0 ;
        int maxx = 0 ;
        for ( int x : gain ) {
            maxx += x ;
            ans = max ( ans , maxx ) ;
        }
        return ans ;
    }
};
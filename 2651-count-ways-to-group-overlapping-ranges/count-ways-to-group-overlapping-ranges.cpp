class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        const int mod = 1e9 + 7 ;
        sort(ranges.begin() , ranges.end()) ;
        int g = 0 , last = -1 ;
        for ( auto x : ranges ) {
            int st = x[0] ;
            int end = x[1] ;
            if ( st > last ) {
                g++ ;
                last = end ;
            }else {
                last = max ( last , end ) ;
            }
        }
        long long ans = 1 ;
        for  ( int i = 0 ; i < g ; i++ ) {
            ans = (ans * 2) % mod ;
        }
        return ans ;
    }
};
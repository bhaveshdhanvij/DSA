class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int ts) {
        sort ( b.begin() , b.end() , [&](const auto& x ,const auto& y) {
            return x[1] > y[1] ;
        });

        int ans = 0 ;
        for ( int i = 0 ; i < b.size() && ts > 0 ; i++ ) {
            int each = b[i][1] ;
            int boxes = b[i][0] ;

            int curr = min ( ts , boxes ) ;
            ans += curr * each ;

            ts -= curr ;
        }

        return ans ;

    }
};
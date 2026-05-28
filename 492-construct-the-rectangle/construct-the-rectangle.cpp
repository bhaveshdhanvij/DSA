class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans ;
        int minn = INT_MAX ;
        for ( int w = sqrt(area) ; w >= 1 ; w-- ) {
            if ( area % w != 0 ) continue ;
            int l = area / w ;
            if ( abs(l - w) < minn ) {
                ans = {l , w} ;
                minn = abs(l - w) ;
            }
        }
        return ans ;
    }
};
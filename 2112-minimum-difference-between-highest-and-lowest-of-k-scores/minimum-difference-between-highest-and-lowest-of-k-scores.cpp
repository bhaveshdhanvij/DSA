class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size() ;

        sort ( a.begin() , a.end() ) ;

        int ans = INT_MAX , l = 0 ;

        for ( int r = 0 ; r < n ; r++ ) {
            if ( r - l + 1 == k ) {
                ans = min ( ans , a[r] - a[l] ) ;
                l++ ;
            }
        }

        return ans ;
    }
};
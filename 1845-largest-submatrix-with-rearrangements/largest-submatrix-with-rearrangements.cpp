class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) {
        int m = a.size() ;
        int n = a[0].size() ;

        for ( int i = 1 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( a[i][j] != 0 ) {
                    a[i][j] += a[i - 1][j] ;
                }
            }
        }

        int ans = 0 ;
        
        for ( int i = 0 ; i < m ; i++ ) {
            vector<int> r = a[i] ;
            sort ( r.rbegin() , r.rend() ) ;

            for ( int j = 0 ; j < n ; j++ ) {
                ans = max ( ans , r[j] * (j + 1) ) ;
            }
        }

        return ans ;
    }
};
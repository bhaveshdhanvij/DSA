class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size() ;
        vector<int> r , c ;
        int ans = 0 ;
        for ( int i = 0 ; i < m ; i++ ) {
            int count = 0 ;
            for ( int j = 0 ; j < n ; j++ ) {
                if ( mat[i][j] == 1 ) count++ ;
            }
            r.push_back(count) ;
        }
        for ( int j = 0 ; j < n ; j++ ) {
            int count = 0 ;
            for ( int i = 0 ; i < m ; i++ ) {
                if ( mat[i][j] == 1 ) count++ ;
            }
            c.push_back(count) ;
        }
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( mat[i][j] == 1 && r[i] == 1 && c[j] == 1 ) ans++ ;
            }
        }
        return ans ;
    }
};
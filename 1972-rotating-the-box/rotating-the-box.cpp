class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n = a.size() , m = a[0].size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            int e = m - 1 ;
            for ( int j = m - 1 ; j >= 0 ; j-- ) {
                if ( a[i][j] == '*' ) {
                    e = j - 1 ;
                }else if ( a[i][j] == '#') {
                    swap(a[i][j] , a[i][e]) ;
                    e-- ;
                }
            }
        }

        vector<vector<char>> ans(m , vector<char>(n)) ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                ans[j][n - i - 1] = a[i][j] ;
            }
        }

        return ans ;
    }
};
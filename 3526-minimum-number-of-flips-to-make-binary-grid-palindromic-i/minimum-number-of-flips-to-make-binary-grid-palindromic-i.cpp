class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        int x = 0 , y = 0 ;
        int m = a.size() , n = a[0].size() ;

        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n / 2 ; j++ ) {
                if ( a[i][j] != a[i][n - j - 1] ) x++ ;
            }
        }

        for ( int j = 0 ; j < n ; j++ ) {
            for ( int i = 0 ; i < m / 2 ; i++ ) {
                if ( a[i][j] != a[m - i - 1][j] ) y++ ;
            }
        }

        return min(x , y) ;
    }
};
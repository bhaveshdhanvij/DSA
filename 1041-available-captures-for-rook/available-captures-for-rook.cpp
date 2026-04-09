class Solution {
public:
    int numRookCaptures(vector<vector<char>>& a) {
        int x = -1 , y = -1 , ans = 0 ;

        for ( int i = 0 ; i < 8 ; i++ ) {
            for ( int j = 0 ; j < 8 ; j++ ) {
                if ( a[i][j] == 'R' ) {
                    x = i ;
                    y = j ;
                    break ;
                }
            }
        }

        for ( int i = x ; i >= 0 ; i-- ) {
            if ( a[i][y] == 'p' ) {
                ans++ ;
                break ;
            }else if ( a[i][y] == 'B') break ;
        }

        for ( int j = y ; j < 8 ; j++ ) {
            if ( a[x][j] == 'p' ) {
                ans++ ;
                break ;
            }else if ( a[x][j] == 'B') break ;
        }

        for ( int i = x ; i < 8 ; i++ ) {
            if ( a[i][y] == 'p' ) {
                ans++ ;
                break ;
            }else if ( a[i][y] == 'B') break ;
        }

        for ( int j = y ; j >= 0 ; j-- ) {
            if ( a[x][j] == 'p' ) {
                ans++ ;
                break ;
            }else if ( a[x][j] == 'B') break ;
        }

        return ans ;
    }
};
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> a(m , vector<char>(n , 'A')) ;

        queue<pair<int,int>> q ;
        for ( auto x : guards ) {
            int r = x[0] , c = x[1] ;
            a[r][c] = 'G' ;
            q.push({r , c}) ;
        }

        for ( auto x : walls ) {
            int r = x[0] , c = x[1] ;
            a[r][c] = 'W' ;
        }

        int delRow[4] = { -1 , 0 , 1 , 0 } ;
        int delCol[4] = { 0 , 1 , 0 , -1 } ;
        
        while ( !q.empty() ) {
            auto [r , c] =  q.front() ;
            q.pop() ;

            for ( int d = 0 ; d < 4 ; d++ ) {
                int nr = r + delRow[d] ;
                int nc = c + delCol[d] ;

                while ( nr >= 0 && nr < m && nc >= 0 && nc < n ) {
                    if ( a[nr][nc] == 'W' || a[nr][nc] == 'G' ) {
                        break ;
                    } 

                    if ( a[nr][nc] == 'A' ) {
                        a[nr][nc] = 'S' ;
                    }

                    nr += delRow[d] ;
                    nc += delCol[d] ;
                }
            }
        }
        int ans = 0 ;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( a[i][j] == 'A' ) {
                    ans++ ;
                }
            }
        }

        return ans ;
    }
};
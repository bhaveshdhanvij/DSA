class Solution {
public:
    long long dfs ( int r , int c , vector<vector<int>>& grid , int delRow[] , int delCol[] ) {
        long long val = grid[r][c] ;
        grid[r][c] = 0 ;
        
        int n = grid.size() ;
        int m = grid[0].size() ;

        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;
            if ( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 0 ) {
                val += dfs(nr , nc , grid , delRow , delCol ) ;
            }
        } 
        return val ;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        int ans = 0 ;

        int delRow[] = { -1 , 0 , 1 , 0 } ;
        int delCol[] = {0 , 1 , 0 , -1} ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] != 0 ) {
                    long long val = dfs(i , j , grid , delRow , delCol ) ;
                    if ( val % k == 0 ) {
                        ans++ ;
                    }
                }
            }
        }

        return ans ;
    }
};
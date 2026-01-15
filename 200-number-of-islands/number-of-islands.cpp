class Solution {
private:
    void dfs ( int r , int c, vector<vector<char>> &grid , int delRow[] , int delCol[] ) {
        grid[r][c] = '0' ;
        
        int n = grid.size() ;
        int m = grid[0].size() ;

        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;
            
            if ( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' ) {
                dfs(nr , nc , grid , delRow , delCol) ;
            }
        }
    } 
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        int ans = 0 ;

        int delRow[] = {-1 , 0 , 1 , 0} ;
        int delCol[] = {0 , 1 , 0 , -1} ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == '1' ) {
                    ans++ ;
                    dfs(i , j , grid , delRow , delCol) ;
                }
            }
        }

        return ans ;
    }
};
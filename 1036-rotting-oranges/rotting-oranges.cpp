class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS since at each minute every rooten orange is making fresh orange rotten 

        int n = grid.size() ;
        int m = grid[0].size() ;

        queue<pair<int,int>> q ;

        int f = 0 ; // this is total fresh oranges count 

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == 2 ) {
                    q.push(make_pair(i , j)) ;
                }else if ( grid[i][j] == 1 ) {
                    f++ ;
                }
            }
        }

        int ans = 0 ; // total minutes 

        int delRow[] = {-1 , 0 , 1 , 0} ;
        int delCol[] = {0 , 1 , 0 , -1} ;

        while ( !q.empty() && f > 0 ) {
            int s = q.size() ;
            ans++ ;

            while (s--) {
                auto [r , c] = q.front() ;
                q.pop() ;

                for ( int i = 0 ; i < 4 ; i++ ) {
                    int nr = r + delRow[i] ;
                    int nc = c + delCol[i] ;
                    
                    if ( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 ) {
                        f-- ;
                        grid[nr][nc] = 2 ;
                        q.push(make_pair(nr , nc)) ;
                    }
                }
            }
        }

        return f == 0 ? ans : -1 ;
    }
};
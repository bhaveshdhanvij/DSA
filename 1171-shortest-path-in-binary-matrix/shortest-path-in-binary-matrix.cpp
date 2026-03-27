class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size() ;
        int c = 0 ;
        if ( n == 1 ) return a[0][0] == 0 ? 1 : -1 ;
        if ( a[0][0] == 1 || a[n - 1][n - 1] == 1 ) return -1 ;

        vector<vector<bool>> vis(n , vector<bool>(n , false)) ;
        queue<pair<int,int>> q ;

        q.push({0 , 0}) ;
        vis[0][0] = true ;
        
        int delRow[] = { -1 , -1 , -1 , 0 , 1 , 1 , 1 , 0 } ;
        int delCol[] = { -1 , 0 , 1 , 1 , 1, 0 , -1 , -1 } ;

        while ( !q.empty() ) {
            int s = q.size() ;
            c++ ;
            while ( s-- ) {
                auto [i , j] = q.front() ;
                q.pop() ;

                if ( i == n - 1 && j == n - 1 ) {
                    return c ;
                }

                for ( int k = 0 ; k < 8 ; k++ ) {
                    int nr = i + delRow[k] ; 
                    int nc = j + delCol[k] ;
                    if ( nr >= 0 && nr < n && nc >= 0 && nc < n && a[nr][nc] == 0 && !vis[nr][nc] ) {
                        q.push({nr , nc}) ;
                        vis[nr][nc] = true ;
                    }
                }
            }
        }

        return -1 ;
    }
};
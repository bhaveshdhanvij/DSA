class Solution {
public:
    int nearestExit(vector<vector<char>>& a, vector<int>& e) {
        int m = a.size() , n = a[0].size() ;
        
        int i = e[0] , j = e[1] ;
        
        queue<pair<int,int>> q ;
        vector<vector<bool>> vis(m , vector<bool>(n , false)) ;

        q.push({i , j}) ;
        vis[i][j] = true ;

        int delRow[4] = { -1 , 0 , 1 , 0 } ;
        int delCol[4] = { 0 , 1 , 0 , -1 } ;

        int curr = 0 ;
        while ( !q.empty() ) {
            int size = q.size() ;
            curr++ ;

            while (size--) {
                auto [r , c] = q.front() ;
                q.pop() ;

                for ( int k = 0 ; k < 4 ; k++ ) {
                    int nr = r + delRow[k] ;
                    int nc = c + delCol[k] ;

                    if ( nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && a[nr][nc] == '.' ) {
                        if ( nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1 ) {
                            return curr ;
                        }

                        q.push({nr , nc}) ;
                        vis[nr][nc] = true ;
                    }
                }
            }
        } 

        return -1 ;
    }
};
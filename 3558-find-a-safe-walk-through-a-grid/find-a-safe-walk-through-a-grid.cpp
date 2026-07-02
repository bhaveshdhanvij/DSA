class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& a, int h) {
        // Optimal Approach : Using BFS : storing maximum health remaining for every cell 
        // best[r][c] => max health left when reaching (r , c) 

        int n = a.size() , m = a[0].size() ;
        
        int st = h - a[0][0] ;
        if ( st <= 0 ) return false ;

        vector<vector<int>> best(n , vector<int>(m , -1)) ;

        best[0][0] = st ;
        queue<pair<int,int>> q ;
        q.push({0 , 0}) ;

        int delRow[4] = {-1 , 0 , 1 , 0} ;
        int delCol[4] = {0 , 1 , 0 , -1} ;

        while (q.size() > 0) {
            auto [r , c] = q.front() ;
            q.pop() ;
            int curr = best[r][c] ;

            if ( r == n - 1 && c == m - 1 ) {
                return true ;
            }

            for ( int k = 0 ; k < 4 ; k++ ) {
                int nr = r + delRow[k] ;
                int nc = c + delCol[k] ;
                

                if ( nr < 0 || nr >= n || nc < 0 || nc >= m ) continue ;

                int nexth = curr - a[nr][nc] ;
                if ( nexth <= 0 ) continue ;

                if ( nexth > best[nr][nc] ) {
                    q.push({nr , nc}) ;
                    best[nr][nc] = nexth ;
                } 
            }
        }

        return false ;
    }
};
class Solution {
public:
    // Linkedin
    // Doordash
    // Google
    // Amazon
    // Flipkart
    // Adobe
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        // Optimal Approach : Multi-level BFS
        // TC : O(N * M) , SC : O(N * M)
        int m = a.size() , n = a[0].size() ;
        vector<vector<int>> d(m , vector<int>(n , INT_MAX)) ;
        // firstly set all 0 => 0's  and all 1's => INF

        queue<pair<int,int>> q ;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( a[i][j] == 0 ) {
                    d[i][j] = 0 ;
                    q.push({i , j}) ;
                }
            }
        }

        int delRow[4] = {-1 , 0 , 1 , 0} ;
        int delCol[4] = {0 , 1 , 0 , -1} ;
        
        while (q.size() > 0) {
            auto [r , c] = q.front() ;
            q.pop() ;

            for ( int i = 0 ; i < 4 ; i++ ) {
                int nr = r + delRow[i] ;
                int nc = c + delCol[i] ;

                if ( nr >= 0 && nr < m && nc >= 0 && nc < n && d[nr][nc] > d[r][c] + 1 ) {
                    d[nr][nc] = d[r][c] + 1 ;
                    q.push({nr , nc}) ;
                }
            }
        }

        return d ;
    }
};
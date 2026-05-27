class Solution {
public:
    // Flipkart
    // Societe generale
    // Apple
    vector<int> spiralOrder(vector<vector<int>>& a) {
        // Naive Approach : Visited Matrix Simulation 
        // TC : O(N * M) , SC : O(N * M)

        int n = a.size() , m = a[0].size() ;
        vector<vector<bool>> vis(n , vector<bool>(m , false)) ;

        vector<int> ans ;
        
        int delRow[4] = { 0 , 1 , 0 , -1 } ;
        int delCol[4] = { 1 , 0 , -1 , 0 } ;
        
        int r = 0 , c = 0 , d = 0 ;

        for ( int i = 0 ; i < m * n ; i++ ) {
            ans.push_back(a[r][c]) ;
            vis[r][c] = true ;

            int nr = r + delRow[d] ;
            int nc = c + delCol[d] ;

            if (!( nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] )) {
                d = (d + 1) % 4 ;

                nr = r + delRow[d] ;
                nc = c + delCol[d] ;
            }

            r = nr ;
            c = nc ;
        }

        return ans ;
    }
};
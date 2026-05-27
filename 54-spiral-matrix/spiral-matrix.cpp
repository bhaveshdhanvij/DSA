class Solution {
public:
    // Flipkart
    // Societe generale
    // Apple
    vector<int> spiralOrder(vector<vector<int>>& a) {
        // Naive Approach : Visited Matrix Simulation 
        // TC : O(N * M) , SC : O(N * M)

        // int n = a.size() , m = a[0].size() ;
        // vector<vector<bool>> vis(n , vector<bool>(m , false)) ;

        // vector<int> ans ;
        
        // int delRow[4] = { 0 , 1 , 0 , -1 } ;
        // int delCol[4] = { 1 , 0 , -1 , 0 } ;
        
        // int r = 0 , c = 0 , d = 0 ;

        // for ( int i = 0 ; i < m * n ; i++ ) {
        //     ans.push_back(a[r][c]) ;
        //     vis[r][c] = true ;

        //     int nr = r + delRow[d] ;
        //     int nc = c + delCol[d] ;

        //     if (!( nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] )) {
        //         d = (d + 1) % 4 ;

        //         nr = r + delRow[d] ;
        //         nc = c + delCol[d] ;
        //     }

        //     r = nr ;
        //     c = nc ;
        // }

        // return ans ;

        
        // Optimal Approach : Boundary Traversal 
        // TC : O(N * M) , SC : O(1) 

        int n = a.size() , m = a[0].size() ;
        int top = 0 , bottom = n - 1 ;
        int left = 0 , right = m - 1 ;

        vector<int> ans ;
        
        while ( top <= bottom && left <= right ) {

            // left to right 
            for ( int i = left ; i <= right ; i++ ) {
                ans.push_back(a[top][i]) ;
            }
            top++ ;

            // top to bottom 
            for ( int i = top ; i <= bottom ; i++ ) {
                ans.push_back(a[i][right]) ;
            }
            right-- ;

            // right to left 
            if ( top <= bottom ) {
                for ( int i = right ; i >= left ; i-- ) {
                    ans.push_back(a[bottom][i]) ;
                }
                bottom-- ;
            }

            // bottom to top    
            if ( left <= right ) {
                for ( int i = bottom ; i >= top ; i-- ) {
                    ans.push_back(a[i][left]) ;
                }
                left++ ;
            }
        }

        return ans ;
    }
};
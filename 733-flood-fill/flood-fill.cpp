class Solution {
public:
    // Uber
    // Amazon
    // Yahoo
    // Adobe
    // Apple
    // Google
    // Microsoft
    int orgcolor , newcolor , m , n ;
    int delRow[4] = {-1 , 0 , 1 , 0} ;
    int delCol[4] = {0 , 1 , 0 , -1} ;

    void helper(vector<vector<int>> &a , int r , int c ) {
        if ( r < 0 || r >= m || c < 0 || c >= n || a[r][c] != orgcolor || a[r][c] == newcolor ) {
            return ;
        }
        a[r][c] = newcolor ;
        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;
            
            helper(a , nr , nc) ;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        // Optimal Approach : DFS based flood fill 
        // TC : O(M * N) , SC : O(M * N) -call stack 
        
        m = a.size() , n = a[0].size() ;
        orgcolor = a[sr][sc] ;
        newcolor = color ;
        helper(a , sr , sc) ;
        return a ;
    }
};
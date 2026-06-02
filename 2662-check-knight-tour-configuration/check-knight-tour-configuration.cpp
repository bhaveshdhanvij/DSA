class Solution {
public:
    // Meta
    // Google
    // Microsoft
    // Amazon
    bool checkValidGrid(vector<vector<int>>& a) {
        // Optimal Approach : Basic backtracking 
        // TC : O(N ** 2) , SC : O(N ** 2)

        int n = a.size() ;
        if ( a[0][0] != 0 ) return false ;
        vector<pair<int,int>> pos(n * n) ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                pos[a[i][j]] = {i , j} ;
            }
        }

        for ( int k = 1 ; k < n * n ; k++ ) {
            int x1 = pos[k - 1].first ;
            int y1 = pos[k - 1].second ;

            int x2 = pos[k].first ; 
            int y2 = pos[k].second ;

            int xd = abs(x2 - x1) ;
            int yd = abs(y2 - y1) ;

            if ( !(xd == 2 && yd == 1) && !(xd == 1 && yd == 2) ) {
                return false ;
            }
        }
        
        return true ;
    }
};
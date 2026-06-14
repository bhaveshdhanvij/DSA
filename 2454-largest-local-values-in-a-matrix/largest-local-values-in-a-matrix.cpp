class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& a) {
        int n = a.size() ;
        vector<vector<int>> ans(n - 2 , vector<int>(n - 2)) ;
        
        int delRow[8] = { -1 , -1 , -1 , 0 , 1 , 1 , 1 , 0 } ;
        int delCol[8] = { -1 , 0 , 1 , 1 , 1 , 0 , -1 , -1 } ;

        for ( int i = 1 ; i < n - 1 ; i++ ) {
            for ( int j = 1 ; j < n - 1 ; j++ ) {
                int maxx = a[i][j] ;
                for ( int k = 0 ; k < 8 ; k++ ) {
                    int nr = i + delRow[k] ;
                    int nc = j + delCol[k] ;
                    maxx = max ( maxx , a[nr][nc] ) ;
                }
                ans[i - 1][j - 1] = maxx ;
            }
        }
        
        return ans ;
    }
};
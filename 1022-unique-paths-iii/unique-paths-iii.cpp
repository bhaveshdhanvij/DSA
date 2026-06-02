class Solution {
public:
    int delRow[4] = {-1 , 0 , 1 , 0} ;
    int delCol[4] = {0 , 1 , 0 , -1} ;
    int ans = 0 ;

    void helper(vector<vector<int>>& a , int row , int col , int x ) {
        int n = a.size() , m = a[0].size() ;
        if ( row < 0 || col < 0 || row >= n || col >= m || a[row][col] == -1 ) {
            return ;
        }
        if ( a[row][col] == 2 ) {
            if ( x == 1 ) {
                ans++ ;
            }
            return ;
        }

        int temp = a[row][col] ;

        a[row][col] = -1 ;

        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = row + delRow[i] ;
            int nc = col + delCol[i] ;
            
            helper(a , nr , nc , x - 1 ) ;
        }

        a[row][col] = temp ;
    }

    int uniquePathsIII(vector<vector<int>>& a) {
        int n = a.size() , m = a[0].size() ;
        int sr , sc ;
        
        int x = 0 ; // no of non-obstacle squares 
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] != -1 ) x++ ;
                if ( a[i][j] == 1 ) {
                    sr = i ;
                    sc = j ;
                }
            }
        }

        helper(a , sr , sc , x) ;

        return ans ;
    }
};
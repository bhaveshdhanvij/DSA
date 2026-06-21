class Solution {
public:
    int m , n , originalcolor ;
    int delRow[4] = {-1 , 0 , 1 , 0} ;
    int delCol[4] = {0 , 1 , 0 , -1} ;
    vector<pair<int,int>> b ;

    void helper(vector<vector<int>> &a , int r , int c , vector<vector<bool>> &vis ) {
        vis[r][c] = true ;
        bool flag = false ;

        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;

            if ( nr < 0 || nr >= m || nc < 0 || nc >= n ) {
                flag = true ;
            }else if ( a[nr][nc] != originalcolor ) {
                flag = true ;
            }else if ( !vis[nr][nc] ) {
                helper(a , nr , nc , vis) ;
            }
        }

        if ( flag ) {
            b.push_back({r , c}) ;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& a, int row, int col, int color) {
        originalcolor = a[row][col] ;
        m = a.size() ;
        n = a[0].size() ;

        vector<vector<bool>> vis(m , vector<bool>(n , false)) ;
        helper(a , row , col , vis) ;

        for ( auto x : b ) {
            int r = x.first ;
            int c = x.second ;
            a[r][c] = color ;
        }

        return a ;
    }
};
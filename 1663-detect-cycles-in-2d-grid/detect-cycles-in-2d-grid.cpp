class Solution {
public:
    int n , m ;
    vector<vector<bool>> vis ;
    int delRow[4] = {-1 , 0 , 1 , 0} ;
    int delCol[4] = {0 , 1 , 0 , -1} ;

    bool helper( vector<vector<char>>& a, int i , int j , int pi , int pj , char ch ) {
        if ( vis[i][j] ) return true ;
        vis[i][j] = true ;
        
        for ( int k = 0 ; k < 4 ; k++ ) {
            int nr = i + delRow[k] ;
            int nc = j + delCol[k] ;
            
            if ( nr >= 0 && nc >= 0 && nr < n && nc < m && a[nr][nc] == ch ) {
                if ( nr == pi && nc == pj ) continue ;
                if ( helper(a , nr , nc , i , j , ch) ) {
                    return true ;
                }
            }
        }
        return false ;
    }

    bool containsCycle(vector<vector<char>>& a) {
        n = a.size() ;
        m = a[0].size() ;

        vis.assign(n , vector<bool>(m , false)) ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( !vis[i][j] ) {
                    if ( helper(a , i , j , -1 , -1 , a[i][j]) ) {
                        return true ;
                    }
                }
            }
        }

        return false ;
    }
};
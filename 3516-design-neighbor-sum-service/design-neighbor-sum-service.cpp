class NeighborSum {
public:
    int delRow[8] = { -1 , 0 , 1 , 0 , -1 , -1 , 1 , 1 } ;
    int delCol[8] = {0 , 1 , 0 , -1 , -1 , 1 , 1 , -1 } ;
    int n ;
    vector<vector<int>> a ;
    unordered_map<int,pair<int,int>> mp ;
    
    NeighborSum(vector<vector<int>>& a) {
        n = a.size() ;
        this->a = a ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                mp[a[i][j]] = {i , j} ;
            }
        }
    }
    
    int adjacentSum(int val) {
        auto [r , c] = mp[val] ;
        
        int sum = 0 ;
        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;

            if ( nr >= 0 && nr < n && nc >= 0 && nc < n ) {
                sum += a[nr][nc] ;
            } 
        }

        return sum ;
    }
    
    int diagonalSum(int val) {
        int sum = 0 ;
        auto [r , c] = mp[val] ;
        for ( int i = 4 ; i < 8 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;

            if ( nr >= 0 && nr < n && nc >= 0 && nc < n ) {
                sum += a[nr][nc] ;
            }
        }

        return sum ;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
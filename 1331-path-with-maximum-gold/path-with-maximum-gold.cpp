class Solution {
public:
    int delRow[4] = {-1 , 0 , 1 , 0} ;
    int delCol[4] = {0 , 1 , 0 , -1} ;  

    void helper( int i , int j , vector<vector<int>>& a, int curr , int &ans ) {
        int n = a.size() , m = a[0].size() ;

        int temp = a[i][j] ;
        curr += a[i][j] ;
        a[i][j] = 0 ;

        ans = max ( ans , curr ) ;

        for ( int k = 0 ; k < 4 ; k++ ) {
            int nr = i + delRow[k] ;
            int nc = j + delCol[k] ;
            if ( nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] != 0 ) {
                helper(nr , nc , a , curr , ans) ;
            }
        }

        a[i][j] = temp ;
    }

    int getMaximumGold(vector<vector<int>>& a) {
        int ans = 0 ;
        int n = a.size() , m = a[0].size() ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] != 0 ) {
                    int curr = 0 ;
                    helper( i , j , a , curr , ans ) ;
                }
            }
        }
        return ans ;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size() , m = a[0].size() ;
        vector<vector<int>> ans(n , vector<int> (m , -1)) ;
        
        queue<pair<int,int>> q ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] == 0 ) {
                    ans[i][j] = 0 ;
                    q.push({i , j}) ;
                }
            }
        }

        int delRow[] = {-1 , 0 , 1 , 0} ;
        int delCol[] = {0 , 1 , 0 , -1} ;

        while ( !q.empty() ) {
            auto [x , y] = q.front() ;
            q.pop() ;

            for ( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + delRow[i] ;
                int ny = y + delCol[i] ;
                
                if ( nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == -1 ) {
                    ans[nx][ny] = 1 + ans[x][y] ;
                    q.push({nx , ny}) ;
                }
            }
        }

        return ans ;
    }
};
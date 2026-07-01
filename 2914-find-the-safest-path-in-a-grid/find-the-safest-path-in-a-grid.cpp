class Solution {
public:
    
    int maximumSafenessFactor(vector<vector<int>>& a) {
        int n = a.size() ;
        vector<vector<int>> d(n , vector<int>(n , INT_MAX)) ;
        queue<pair<int,int>> q ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( a[i][j] == 1 ) {
                    d[i][j] = 0 ;
                    q.push({i , j}) ;
                }
            }
        }

        int delRow[4] = {-1 , 0 , 1 , 0} ;
        int delCol[4] = {0 , 1 , 0 , -1} ;


        while (!q.empty()) {
            auto [r , c] = q.front() ;
            q.pop() ;

            for ( int k = 0 ; k < 4 ; k++ ) {
                int nr = r + delRow[k] ;
                int nc = c + delCol[k] ;

                if ( nr >= 0 && nr < n && nc >= 0 && nc < n && d[nr][nc] == INT_MAX ) {
                    d[nr][nc] = d[r][c] + 1 ;
                    q.push({nr , nc}) ;
                } 
            }
        }


        auto can = [&](int safe) {
            if ( d[0][0] < safe ) return false ;
            vector<vector<int>> vis(n , vector<int>(n , 0)) ;
            queue<pair<int,int>> qq ;

            qq.push({0 , 0}) ;
            vis[0][0] = 1 ;
            while (!qq.empty()) {
                auto [r , c] = qq.front() ;
                qq.pop() ;

                if ( r == n - 1 && c == n - 1 ) {
                    return true ;
                }

                for ( int i = 0 ; i < 4 ; i++ ) {
                    int nr = r + delRow[i] ;
                    int nc = c + delCol[i] ;

                    if ( nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc] && d[nr][nc] >= safe ) {
                        vis[nr][nc] = 1 ;
                        qq.push({nr , nc}) ;  
                    }
                }
            }
            return false ;
        };

        int l = 0 , h = 2 * n , ans = 0 ;
        while ( l <= h ) {
            int mid = l + (h - l) / 2 ;
            if ( can(mid) ) {
                ans = mid ;
                l = mid + 1 ;
            }else {
                h = mid - 1 ;
            }
        }
        return ans ;
    }
};
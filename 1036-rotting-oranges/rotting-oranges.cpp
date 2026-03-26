class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        // Optimal Approach : BFS (parallel processing)
        // TC : O(N * M) , SC : O(N * M)
        // BFS used since every rotten orange is making surrounding fresh orange rotten 
        int n = a.size() , m = a[0].size() ;
        queue<pair<int,int>> q ;
        
        int f = 0 ; // count of fresh oranges 

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] == 2 ) q.push({i , j}) ;
                else if ( a[i][j] == 1 ) f++ ;
            }
        }

        int delRow[] = {-1 , 0 , 1 , 0} ;
        int delCol[] = {0 , 1 , 0 , -1} ;

        int t = 0 ; // time taken ie ans

        while ( !q.empty() && f > 0 ) {
            int s = q.size() ; // current no of rotten oranges (curr level)
            t++ ;

            while (s--) {
                auto p = q.front() ;
                q.pop() ;

                int i = p.first , j = p.second ;

                for ( int k = 0 ; k < 4 ; k++ ) {
                    int nr = i + delRow[k] ;
                    int nc = j + delCol[k] ;
                    
                    if ( nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == 1 ) {
                        f-- ;
                        a[nr][nc] = 2 ;
                        q.push({nr , nc}) ;
                    }
                }
            }
        }

        return f == 0 ? t : -1 ; // checking if all fresh oranges became rotten or not 
    }
};
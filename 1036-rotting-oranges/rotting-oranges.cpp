class Solution {
public:
    // Amazon
    // Flipkart
    // Intuit
    // Samsung
    // Oracle
    // Meta
    // Phone Pe
    // Microsoft
    // Google
    int orangesRotting(vector<vector<int>>& a) { // grid -> a
        // Optimal Approach : Multi Source BFS 
        // TC : O(N * M) , SC : O(N * M)

        int n = a.size() , m = a[0].size() ;
        
        queue<pair<int,int>> q ; // for storing indices of rotten oranges as a pair
        int f = 0 ; // count of fresh orange 

        int t = 0 ; // No. of time until all fresh oranges become rotten 

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] == 1 ) f++ ;
                else if ( a[i][j] == 2 ) {
                    q.push({i , j}) ;
                } 
            }
        }

        if ( f == 0 ) return 0 ;

        int delRow[4] = {-1 , 0 , 1 , 0} ;
        int delCol[4] = {0 , 1 , 0 , -1} ;

        while(!q.empty() && f > 0) {
            int size = q.size() ;
            while (size--) {
                auto x = q.front() ;
                q.pop() ;
                
                int r = x.first , c = x.second ;
                
                for ( int i = 0 ; i < 4 ; i++ ) {
                    int nr = r + delRow[i] ;
                    int nc = c + delCol[i] ;
                    
                    if ( nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == 1 ) {
                        f-- ;
                        a[nr][nc] = 2 ;
                        q.push({nr , nc}) ;
                    }
                }
            }
            t++ ;
        }

        return f == 0 ? t : -1 ; // if some fresh orange remain then -1 , else time taken 
    }
};
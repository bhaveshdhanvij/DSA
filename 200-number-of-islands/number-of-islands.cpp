class Solution {
public:
    void helper( int i , int j , vector<vector<char>>& a, int delRow[] , int delCol[] ) {
        int n = a.size() , m = a[0].size() ;
        if ( i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '0' ) return ;

        a[i][j] = '0' ;
        for ( int k = 0 ; k < 4 ; k++ ) {
            int nr = i + delRow[k] ;
            int nc = j + delCol[k] ;
            helper( nr , nc , a , delRow , delCol) ;
        }
    }
    int numIslands(vector<vector<char>>& a) {
        // TC : O(N * M) , SC : O(N * M)
        // Optimal Approach : Using DFS to count the no of groups and flood filling 
        int n = a.size() , m = a[0].size() ;
        int c = 0 ; // no of islands

        int delRow[] = {-1 , 0 , 1 , 0} ;
        int delCol[] = {0 , 1 , 0 , -1} ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] == '1' ) {
                    c++ ;
                    helper(i , j , a , delRow , delCol) ;
                }
            }
        }

        return c ;
    }
};
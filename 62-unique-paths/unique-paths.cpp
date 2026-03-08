class Solution {
public:
    int memo[100][100] ;
    
    int solve( int i , int j , int m , int n ) {
        if ( i >= m || j >= n ) return 0 ;

        if ( i == m - 1 && j == n - 1 ) return 1 ;

        if ( memo[i][j] != -1 ) return memo[i][j] ;
        else {
            return memo[i][j] = solve(i + 1 , j , m , n) + solve(i , j + 1 , m , n) ;
        }
    }
    int uniquePaths(int m, int n) {
        memset(memo , -1 , sizeof(memo)) ;
        return solve(0 , 0 , m , n) ;
    }
};
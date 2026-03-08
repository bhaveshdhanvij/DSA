class Solution {
public:
    int memo[201][201] ;
    
    int solve( int i , int j , int m , int n , vector<vector<int>>& a) {
        if ( i >= m || j >= n ) return INT_MAX ;

        if ( i == m - 1 && j == n - 1 ) return a[i][j] ;

        if ( memo[i][j] != -1 ) return memo[i][j] ;
        else {
            int right = solve(i , j + 1 , m , n , a) ;
            int bottom = solve(i + 1 , j , m , n , a) ;

            return memo[i][j] = a[i][j] + min(right , bottom) ;
        }
    }

    int minPathSum(vector<vector<int>>& a) {
        int m = a.size() ;
        int n = a[0].size() ;

        memset(memo, -1 , sizeof(memo)) ;
        
        return solve(0 , 0 , m , n , a) ;
    }
};
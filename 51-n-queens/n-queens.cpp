class Solution {
public:
    // Apple
    // citadel
    // Meta
    // Google
    // Microsoft
    // Oracle
    // Salesforce
    // Amazon
    // TCS
    bool isSafe(vector<string>& a, int row , int col , int n ) { // O(N)
        // horizontal 
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[row][j] == 'Q' ) {
                return false ;
            }
        }

        // vertical 
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[j][col] == 'Q' ) {
                return false ;
            }
        }

        // left diagonal 

        for ( int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j-- ) {
            if ( a[i][j] == 'Q' ) {
                return false ;
            }
        }

        // right diagonal 

        for ( int i = row , j = col ; i >= 0 && j < n ; i-- , j++ ) {
            if ( a[i][j] == 'Q' ) {
                return false ;
            }
        }
        
        return true ;
    }
    void nQueens(vector<string>& a , int row , int n , vector<vector<string>>& ans ) {
        if ( row == n ) {
            ans.push_back(a) ;
            return ;
        }
        
        for ( int j = 0 ; j < n ; j++ ) {
            if ( isSafe(a , row , j , n) ) {
                a[row][j] = 'Q' ;
                nQueens(a , row + 1 , n , ans ) ;
                a[row][j] = '.' ;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // Optimized Approach : Backtracking 
        // TC : O(N!) , SC : O(N ** 2)

        vector<string> a(n , string(n , '.')) ;
        vector<vector<string>> ans ;

        nQueens(a , 0 , n , ans) ;
        return ans ;
    }
};
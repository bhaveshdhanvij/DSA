class Solution {
private:
    int delRow[4] = { -1 , 0 , 1 , 0 } ;
    int delCol[4] = { 0 , 1 , 0 , -1 } ;
public:
    // Ola
    // Goldman Sachs
    // Google

    // bool helper( int r , int c , vector<vector<char>>& a , int n , int m , int idx , string s , int size , vector<vector<bool>>& vis ) {
    //     if ( idx == size ) {
    //         return true ;
    //     }
    //     vis[r][c] = true ;
    //     for ( int i = 0 ; i < 4 ; i++ ) {
    //         int nr = r + delRow[i] ;
    //         int nc = c + delCol[i] ;
    //         if ( nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == false && s[idx] == a[nr][nc] ) {
    //             if ( helper(nr , nc , a , n , m , idx + 1 , s , size , vis) ) {
    //                 return true ;
    //             }
    //         }
    //     }
    //     vis[r][c] = false ;
    //     return false ;
    // }

    bool helper( int r  , int c , vector<vector<char>>& a , int n , int m , int idx , string s , int size ) {
        if ( idx == size ) {
            return true ;
        }
        char ch = a[r][c] ;
        a[r][c] = '@' ;
        for ( int i = 0 ; i < 4 ; i++ ) {
            int nr = r + delRow[i] ;
            int nc = c + delCol[i] ;
            if ( nr >= 0 && nr < n && nc >= 0 && nc < m && s[idx] == a[nr][nc] ) {
                if ( helper(nr , nc , a , n , m , idx + 1 , s , size) ) {
                    return true ;
                }
            }
        }
        a[r][c] = ch ;
        return false ;
    }

    bool exist(vector<vector<char>>& a, string s) {
        // Approach 1 : Backtracking + visited 2d array 
        // TC : O(M * N * 4 ** k) , SC : O(M * N) + O(K) 

        // int n = a.size() , m = a[0].size() ;
        // char ch = s[0] ;
        // int size = s.size() ;
        // vector<vector<bool>> vis(n , vector<bool>(m , false)) ;
        
        // for ( int i = 0 ; i < n ; i++ ) {
        //     for ( int j = 0 ; j < m ; j++ ) {
        //         if ( a[i][j] == ch ) {
        //             if ( helper(i , j , a , n , m , 1 , s , size , vis) ) {
        //                 return true ;
        //             }
        //         }
        //     }
        // }

        // return false ;

        // Optimal Approach : Backtracking + In-place modification 
        // TC : O(N * M * 4 ** K) , SC : O(K) , k is the length of word 
        
        int n = a.size() , m = a[0].size() ;
        int size = s.length() ;
        char ch = s[0] ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i][j] == ch ) {
                    if ( helper(i , j , a , n , m , 1 , s , size) ) {
                        return true ;
                    }
                }
            }
        }

        return false ;
    }
};
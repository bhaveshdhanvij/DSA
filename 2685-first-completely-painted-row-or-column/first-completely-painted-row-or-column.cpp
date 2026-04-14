class Solution {
public:
    int firstCompleteIndex(vector<int>& a, vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size() ;
        unordered_map<int,pair<int,int>> mp ;

        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                mp[mat[i][j]] = {i , j} ; 
            }
        }

        vector<int> row(m , 0) , col(n , 0) ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            auto [r , c] = mp[a[i]] ;

            row[r]++ ;
            col[c]++ ;

            if ( row[r] == n || col[c] == m ) return i ;
        }

        return -1 ;
    }
};
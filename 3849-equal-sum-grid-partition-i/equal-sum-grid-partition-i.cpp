class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& a) {
        int n = a.size() , m = a[0].size() ;
        long long sum = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m; j++ ) {
                sum += a[i][j] ;
            }
        }

        if ( sum % 2 == 1 ) return false ;

        long long t = sum / 2 , s = 0 ;

        for ( int i = 0 ; i < n - 1 ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                s += a[i][j] ;
            }

            if ( s == t ) return true ;
        }

        s = 0 ;
        for ( int j = 0 ; j < m - 1 ; j++ ) {
            for ( int i = 0 ; i < n ; i++ ) {
                s += a[i][j] ;
            }

            if ( s == t ) return true ;
        }

        return false ;
    }
};
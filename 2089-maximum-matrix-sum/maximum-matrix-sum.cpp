class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size() ;
        long long sum = 0 ;
        int minn = INT_MAX ;
        int count = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                sum += abs(a[i][j]) ;
                minn = min ( minn , abs(a[i][j])) ;
                if ( a[i][j] < 0 ) count++ ;
            }
        }
        if ( count % 2 == 0 ) return sum ;
        return sum - 2 * minn ;
    }
};
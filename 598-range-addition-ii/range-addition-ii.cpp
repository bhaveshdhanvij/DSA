class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if ( ops.empty() ) return m * n ;
        
        int a = m , b = n ;
        for ( auto x : ops ) {
            a = min ( a , x[0] ) ;
            b = min ( b , x[1] ) ;
        }

        return a * b ;
    }
};
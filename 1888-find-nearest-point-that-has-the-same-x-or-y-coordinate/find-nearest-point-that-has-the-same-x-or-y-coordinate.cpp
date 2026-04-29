class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& a) {
        int idx = -1 , minn = INT_MAX ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            int nx = a[i][0] ;
            int ny = a[i][1] ;

            int curr = INT_MAX ;
            
            if ( nx == x || ny == y ) {
                curr = abs(ny - y) + abs(nx - x) ;
            }

            if ( curr < minn ) {
                minn = curr ;
                idx = i ;
            }
        }    

        return idx ;
    }
};
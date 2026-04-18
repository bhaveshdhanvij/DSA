class Solution {
public:
    int helper( int target , vector<int>& t , vector<int>& b ) {
        int n = t.size() ;
        int x = 0 , y = 0 ; // top rotation | bottom rotation 

        for ( int i = 0 ; i < n ; i++ ) {
            if ( t[i] != target && b[i] != target ) {
                return INT_MAX ; 
            }

            if ( t[i] != target ) x++ ;
            
            if ( b[i] != target ) y++ ;
        }

        return min(x , y) ;
    }
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int ans = min ( helper(t[0] , t , b) , helper(b[0] , t , b ) ) ;
        
        return ans == INT_MAX ? -1 : ans ;
    }
};
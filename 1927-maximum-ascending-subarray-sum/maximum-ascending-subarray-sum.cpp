class Solution {
public:
    int maxAscendingSum(vector<int>& a) {
        // Simple Prefix sum array 
        int n = a.size() ;
        vector<int> t = a ;

        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i] > a[i - 1] ) {
                t[i] += t[i - 1] ;
            }
        }

        int ans = 0 ; 
        for ( int x : t ) {
            ans = max ( ans , x ) ;
        }

        return ans ;
    }
};
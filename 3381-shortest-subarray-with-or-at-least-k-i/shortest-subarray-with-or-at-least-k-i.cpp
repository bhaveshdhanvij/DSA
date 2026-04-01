class Solution {
public:
    int minimumSubarrayLength(vector<int>& a, int k) {
        int n = a.size() ;
        int ans = INT_MAX ;
        for ( int i = 0 ; i < n ; i++ ) {
            int curr = 0 ;
            for ( int j = i ; j < n ; j++ ) {
                curr |= a[j] ;
                if ( curr >= k ) {
                    ans = min ( ans , j - i + 1 ) ;
                    break ;
                }
            }  
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};
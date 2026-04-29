class Solution {
public:
    int maxAdjacentDistance(vector<int>& a) {
        int n = a.size() ;
        int ans = abs(a[0] - a[n - 1]) ;
        
        for ( int i = 1 ; i < n ; i++ ) {
            ans = max ( ans , abs(a[i] - a[i - 1]) ) ;
        }

        return ans ;
    }
};
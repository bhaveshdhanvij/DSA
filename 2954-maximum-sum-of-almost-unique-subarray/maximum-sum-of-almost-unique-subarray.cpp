class Solution {
public:
    long long maxSum(vector<int>& a, int m, int k) {
        int n = a.size() ;
        long long ans = 0 , curr = 0 ;
        unordered_map<int,int> mp ;
        int l = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            curr += a[r] ;
            mp[a[r]]++ ;
            if ( r - l + 1 == k ) {
                if ( mp.size() >= m ) {
                    ans = max ( ans , curr ) ;
                }
                mp[a[l]]-- ;
                if ( mp[a[l]] == 0 ) mp.erase(a[l]) ;
                curr -= a[l] ;
                l++ ;
            }
        }
        return ans ;
    }
};
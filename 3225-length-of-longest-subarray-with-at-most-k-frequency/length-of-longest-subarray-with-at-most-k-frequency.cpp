class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size() ;
        int l = 0 , ans = 0 ;
        unordered_map<int,int> mp ;
        for (int r = 0 ; r < n ; r++) {
            mp[a[r]]++ ;
            while ( mp[a[r]] > k ) {
                mp[a[l]]-- ;
                l++ ;
            }
            ans = max ( ans , r - l + 1 ) ;
        }
        return ans ;
    }
};
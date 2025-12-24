class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() ;
        map<int,int> mp ;
        int l = 0 , ans = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            mp[nums[r]]++ ;
            while ( mp[nums[r]] > k ) {
                mp[nums[l]]-- ;
                if ( mp[nums[l]] == 0 ) mp.erase(nums[l]) ;
                l++ ;
            }
            ans = max ( ans , r - l + 1 ) ;
        }
        return ans ;
    }
};
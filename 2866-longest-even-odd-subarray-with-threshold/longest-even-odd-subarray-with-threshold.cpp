class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {  
        int n = nums.size() ;
        int ans = 0 ;
        for ( int l = 0 ; l < n ; l++ ) {
            if ( nums[l] > threshold || nums[l] % 2 != 0 ) continue ;
            int r = l ;
            while ( r < n && nums[r] <= threshold && (r == l || (nums[r] & 1) != (nums[r - 1] & 1) ) ) {
                r++ ;
            }
            ans = max ( ans , r - l ) ;
        }
        return ans ;
    }
};
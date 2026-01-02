class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Approach 1 : Sliding Window 
        // TC : O(N) , SC : O(1)
        int n = nums.size() ;
        int ans = INT_MAX ;
        int l = 0 ;
        int sum = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            sum += nums[r] ;
            while ( sum >= target ) {
                ans = min ( ans , r - l + 1 ) ;
                sum -= nums[l] ;
                l++ ;
            }
        } 
        return ans == INT_MAX ? 0 : ans ; // ternary operator used for optimization
    }
};
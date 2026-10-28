class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN ;
        int n = nums.size() ;
        int l = 0 ; 
        double sum = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            sum += nums[r] ;
            if ( r - l + 1 == k ) {
                ans = max ( ans , sum / k ) ;
                sum -= nums[l] ;
                l++ ;
            }
        }
        return ans ;
    }
};
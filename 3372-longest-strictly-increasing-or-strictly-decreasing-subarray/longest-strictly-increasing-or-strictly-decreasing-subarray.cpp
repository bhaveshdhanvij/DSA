class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() , ans = 1 ;
        int c1 = 1 , c2 = 1 ;
        for ( int i = 1 ; i < n ; i++ ) {
            if ( nums[i] > nums[i - 1] ) {
                c2 = 1 ;
                c1++ ;
            }else if ( nums[i] < nums[i - 1] ) {
                c1 = 1 ;
                c2++ ;
            }else {
                c1 = 1 ;
                c2 = 1 ;
            }
            ans = max ( ans , c1 ) ;
            ans = max ( ans , c2 ) ;
        }
        return ans ;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        int maxx = 0 , end = 0 , ans = 0 ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            maxx = max ( maxx , i + nums[i] ) ;
            if ( i == end ) {
                ans++ ;
                end = maxx ;
            }
        }
        return ans ;
    }
};
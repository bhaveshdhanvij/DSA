class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort ( nums.begin() , nums.end() ) ;
        int ans = 1 , st = nums[0] ;

        for ( int i = 1 ; i < nums.size() ; i++ ) {
            if ( nums[i] - st > k ) {
                ans++ ;
                st = nums[i] ;
            }
        }

        return ans ;
    }
};
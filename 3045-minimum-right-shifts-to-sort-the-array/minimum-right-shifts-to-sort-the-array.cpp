class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size() ;
        int count = 0 , idx = -1 ;
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            if ( nums[i - 1] > nums[i] ) {
                count++ ;
                if ( idx == -1 ) {
                    idx = i ;
                }else {
                    return -1 ;
                }
            }
        }
        if ( count == 1 && nums[n - 1] > nums[0] ) return -1 ;
        if ( count == 0 ) return 0 ;
        return n - idx ;
    }
};
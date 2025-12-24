class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> a = nums ;
        for (int x : nums) a.push_back(x) ;
        int one = 0 ;
        for ( int x : nums ) {
            if ( x == 1 ) one++ ;
        }
        int l = 0 , ans = INT_MAX , zero = 0 ;
        for ( int r = 0 ; r < a.size() ; r++ ) {
            if ( a[r] == 0 ) zero++ ;
            if ( r - l + 1 == one ) {
                ans = min ( ans , zero ) ;
                if ( a[l] == 0 ) zero-- ;
                l++ ;
            } 
        }
        return ans == INT_MAX ? 0 : ans ;
    }
};
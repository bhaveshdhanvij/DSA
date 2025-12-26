class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size() ;
        map<int,int> mp ;
        mp[0] = -1 ;
        int ans = 0 , c = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            c += (nums[i] == 0) ? -1 : 1 ;

            if ( mp.count(c) ) {
                ans = max ( ans , i - mp[c] ) ;
            }else {
                mp[c] = i ;
            }
        }
        return ans ;
    }
};
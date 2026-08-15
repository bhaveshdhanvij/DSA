class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;
        for (int x : nums) ans ^= x ;
        if ( ans != 0 ) return n ;
        bool flag = true ;
        for (int x : nums) {
            if ( x != 0 ) {
                flag = false ;
                break ;
            }
        }
        if ( flag ) return 0 ;
        return n - 1 ;
    }
};
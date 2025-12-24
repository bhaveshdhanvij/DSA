class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size() ;
        vector<long long> prefix(n , 0) ;
        int maxx = INT_MIN ;
        for ( int i = 0 ; i < n ; i++ ) {
            maxx = max ( maxx , nums[i] ) ;
            prefix[i] = nums[i] + maxx ;
        }
        for ( int i = 1 ; i < n ; i++ ) {
            prefix[i] += prefix[i - 1] ;
        }
        return prefix ;
    }
};
class Solution {
public:
    int helper( vector<int> nums , int sum ) {
        int l = 0 , h = nums.size() - 1 ;
        while ( l <= h ) {
            int mid = l + (h - l) / 2 ;
            if ( sum < nums[mid] ) {
                h = mid - 1 ;
            }else {
                l = mid + 1 ;
            }
        }
        return l ;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort ( nums.begin() , nums.end() ) ;
        int n = nums.size() ;
        int m = queries.size() ;
        vector<int> ans(m) ;
        for ( int i = 1 ; i < n ; i++ ) nums[i] += nums[i - 1] ;
        for ( int i = 0 ; i < m ; i++ ) {
            ans[i] = helper( nums , queries[i] ) ;
        }
        return ans ;
    }
};
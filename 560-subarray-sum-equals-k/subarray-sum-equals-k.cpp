class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // TC : O(n) | SC : O(n) 
        unordered_map<int,int> umap ;
        umap[0] = 1 ;

        int ans = 0 ;
        int sum = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            sum += nums[i] ;
            if ( umap.count(sum - k) ) {
                ans += umap[sum - k] ;
            }
            umap[sum]++ ;
        }

        return ans ;
    }
};
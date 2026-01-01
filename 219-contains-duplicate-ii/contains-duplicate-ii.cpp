class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // // HashMap - Index Tracking SC : O(N) , TC :O(N) ;
        // unordered_map<int,int> umap ;
        // for ( int i = 0 ; i < nums.size() ; i++ ) {
        //     if ( umap.count(nums[i]) && i - umap[nums[i]] <= k ) return true ;
        //     umap[nums[i]] = i ;
        // }
        // return false ;


        // HashSet + Sliding window 
        // SC : O(K) , TC : O(N)
        unordered_set<int> uset ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( uset.count(nums[i])) return true ;
            uset.insert(nums[i]) ;
            if ( uset.size() > k) uset.erase(nums[i - k]) ;
        }
        return false ;

    }
};
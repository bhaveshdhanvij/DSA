class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // Approach 1 : Brute Force
        // // TC : O(N2) SC : O(1) 
        // int n = nums.size() ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     for ( int j = i + 1 ; j < n ; j++ ) {
        //         if ( nums[i] + nums[j] == target ) return {i , j} ;
        //     }
        // }
        // return {-1 , -1} ;

        //Approach 1 : HashMap 
        // TC :O(N) , SC : O(N) 
        unordered_map<int,int> umap ;
        int n = nums.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            int t = target - nums[i] ;
            if ( umap.count(t) ) {
                return {i , umap[t]} ;
            }
            umap[nums[i]] = i ;
        }
        return {-1 , -1} ;
    }
};
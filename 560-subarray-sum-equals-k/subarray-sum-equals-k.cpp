class Solution {
public:
    // Microsoft
    // Snapdeal
    int subarraySum(vector<int>& nums, int k) {
        // Naive Approach : Using 2 for loops
        // TC : O(N * N) , SC : O(1) 

        // int n = nums.size() ;   
        // int count = 0 ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     int sum = 0 ;
        //     for ( int j = i ; j < n ; j++ ) {
        //         sum += nums[j] ;
        //         if ( sum == k ) {
        //             count++ ;
        //         }
        //     }
        // }
        // return count ;


        // Optimal Approach : Using Hashing + Prefix Sum  
        // TC : O(N) , SC : O(N) 

        int n = nums.size() ;
        unordered_map<int,int> mp ;
        int sum = 0 , ans = 0 ;
        mp[0] = 1 ;
        for ( int i = 0 ; i < n ; i++ ) {
            sum += nums[i] ;
            if ( mp.count(sum - k) ) {
                ans += mp[sum - k] ;
            }
            mp[sum]++ ;
        }
        return ans ;
    }
};
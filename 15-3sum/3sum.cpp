class Solution {
public:
    // Times Internet
    // Snapdeal
    // Samsung
    // Microsoft
    // Amazon
    // Adobe
    // Service Based:-
    // Morgan Stanley
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Brute Force Approach : using nested loops 
        // TC : O(N ** 3log(k)) , SC : O(K) ;

        // Optimal Approach : Two pointer 

        int n = nums.size() ;
        vector<vector<int>> ans ;
        
        sort ( nums.begin() , nums.end() ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( i > 0 && nums[i] == nums[i - 1] ) continue ;

            int target = -1 * nums[i] ;
            int left = i + 1 , right = n - 1 ;

            while ( left < right ) {
                int sum = nums[left] + nums[right] ;
                if ( sum == target ) {
                    ans.push_back({nums[i] , nums[left] , nums[right]}) ;

                    while ( left < right && nums[left] == nums[left + 1] ) left++ ;
                    while ( left < right && nums[right] == nums[right - 1] ) right-- ;

                    left++ ;
                    right-- ;
                }else if ( sum < target ) {
                    left++ ;
                }else {
                    right-- ;
                }
            }
        }
        return ans ;
    }
};
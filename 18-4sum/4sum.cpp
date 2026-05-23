class Solution {
public:
    // Product Based:-
    // Adobe
    // OYO
    // Uber
    // Microsoft
    // Apple
    // Rubrik
    // Service Based:-
    // TCS
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Brute Force approach : use 4 nested loops 
        // TC : O(N ** 4) , SC : O(k) 

        // Optimal Approach : using 2 loops + two pointers 
        // TC : O(N ** 3) , SC : O(1) 

        int n = nums.size() ;
        vector<vector<int>> ans ;
        sort ( nums.begin() , nums.end() ) ;

        for ( int first = 0 ; first < n - 3 ; first++ ) {
            if ( first > 0 && nums[first] == nums[first - 1] ) continue ;

            for ( int second = first + 1 ; second < n - 2 ; second++ ) {
                if ( second > first + 1 && nums[second] == nums[second - 1] ) continue ;

                long long remtarget = (long long)target - nums[first] - nums[second] ;
                int left = second + 1 , right = n - 1 ;

                while ( left < right ) {
                    int sum = nums[left] + nums[right] ;
                    if ( sum == remtarget ) {
                        ans.push_back({nums[first] , nums[second] , nums[left] , nums[right]}) ;


                        while ( left < right && nums[left] == nums[left + 1] ) left++ ;
                        while ( left < right && nums[right] == nums[right - 1] ) right-- ;

                        left++ ;
                        right-- ;
                    }else if ( sum < remtarget ) {
                        left++ ;
                    }else {
                        right-- ;
                    }
                }
            }
        }
        return ans ;
    }   
};
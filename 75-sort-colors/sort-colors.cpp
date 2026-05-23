class Solution {
public:
    // MakeMyTrip
    // Amazon
    // Microsoft
    void sortColors(vector<int>& nums) {
        // Approach 1 : Two pass sort : first pass : move 0's to front and then move 1's after that
        // TC : O(N) , SC : O(1) 

        // int n = nums.size() ;
        // int i = -1 ;
        // for ( int j = 0 ; j < n ; j++ ) {
        //     if ( nums[j] == 0 ) {
        //         i++ ;
        //         swap(nums[i] , nums[j]) ;
        //     }
        // }
        // int k = i + 1 ; // search for 1 now from i + 1 
        // for ( int j = k ; j < n ; j++ ) {
        //     if ( nums[j] == 1 ) {
        //         i++ ;
        //         swap(nums[i] , nums[j]) ;
        //     }
        // }

        // Optimal Approach : Dutch National Flag Algorithm : using three pointers low , mid , high 
        // TC : O(N) , SC : O(1) 

        int n = nums.size() ;
        int low = 0 , mid = 0 , high = n - 1 ;
        while ( mid <= high ) {
            if ( nums[mid] == 0 ) {
                swap(nums[low] , nums[mid]) ;
                low++ ;
                mid++ ;
            }else if ( nums[mid] == 1 ) {
                mid++ ;
            }else {
                swap(nums[mid] , nums[high]) ;
                high-- ;
            }
        }
    }
};
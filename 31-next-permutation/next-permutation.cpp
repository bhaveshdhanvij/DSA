class Solution {
private:
    
public:
    // Uber
    // Goldman Sachs
    // Adobe
    void nextPermutation(vector<int>& nums) {
        // Naive Approach : finding all permutations using hashSet 
        // TC : O(N * N!) , SC : O(n!) + O(n) 

        // Optimal Approach : Next permutation algorithm 
        // 1. Locate the rightmost decreasing algorithm 
        // 2. Locate the next bigger component to exchange 
        // 3.Reverse the right part after the swap (suffix) 

        // TC : O(N) , SC : O(1) 
        int n = nums.size() ;
        int idx = -1 ;
        
        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            if ( nums[i] < nums[i + 1] ) {
                idx = i ;
                break ;
            }
        }
        
        if ( idx != -1 ) {
            for ( int i = n - 1 ; i > idx ; i-- ) {
                if ( nums[i] > nums[idx] ) {
                    swap(nums[i] , nums[idx]) ;
                    break ;
                }
            }
        }

        reverse( nums.begin() + idx + 1 , nums.end() ) ;
    }
};
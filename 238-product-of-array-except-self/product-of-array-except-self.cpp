class Solution {
public:
    // Ola
    // Goldman Sachs
    // Google
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute Force : Using double for loops and fill the ans array 
        // TC : O(N * N) , SC : O(1) 

        // Approach 2 : Division method + Greedy
        // TC : O(N) , SC : O(1) 

        int n = nums.size() ;
        int p = 1 , c = 0 ;
        for ( int x : nums ) {
            if ( x == 0 ) c++ ;
            else p *= x ;
        }

        vector<int> ans ;
        for ( int x : nums ) {
            if ( x == 0 ) {
                if ( c == 1 ) ans.push_back(p) ;
                else ans.push_back(0) ;
            }else {
                if ( c == 0 ) ans.push_back(p / x) ;
                else ans.push_back(0) ;
            }
        }

        return ans ;
    }
};
class Solution {
public:
    // Swiggy
    // Apple
    // Meta
    // Uber
    // Flipkart
    // Adobe
    // Microsoft
    // Amazon
    // Google
    // TCS  
    void helper( vector<int>& nums , vector<int> &curr , vector<vector<int>> &ans , int i) {
        if ( i == nums.size() ) {
            ans.push_back(curr) ;
            return ;
        }

        // include 
        curr.push_back(nums[i]) ;
        helper(nums , curr , ans , i + 1) ;

        curr.pop_back() ; // backtrack 

        int idx = i + 1 ;
        while ( idx < nums.size() && nums[idx] == nums[idx - 1] ) idx++ ;

        helper(nums , curr , ans , idx ) ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Basic backtracking 
        // TC : O(Nlog(N) + N * 2^N) 
        
        sort ( nums.begin() , nums.end() ) ;
        vector<vector<int>> ans ;
        vector<int> curr ;
        helper(nums , curr , ans , 0) ;
        return ans ;
    }
};
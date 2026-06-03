class Solution {
public:
    void helper(vector<int>& nums , vector<int> &curr , int idx , vector<vector<int>> &ans) {
        if ( idx == nums.size() ) {
            // store subsets 
            ans.push_back(curr) ;
            return ;
        }

        // include 
        curr.push_back(nums[idx]) ;
        helper(nums , curr , idx + 1 , ans) ;

        curr.pop_back() ; // backtrack 
        
        // exclude  
        helper(nums , curr , idx + 1 , ans) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // TC : O(N * 2^N )
        vector<vector<int>> ans ;
        vector<int> curr ;
        helper(nums , curr , 0 , ans) ;
        return ans ;
    }
};
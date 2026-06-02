class Solution {
public:
    // Microsoft
    // Amazon
    // DE Shaw
    // Salesforce
    // Oracle
    // Adobe
    void helper(vector<int>&a , int target , int st , vector<int>& curr , vector<vector<int>>& ans) {
        if ( target == 0 ) {
            ans.push_back(curr) ;
            return ;
        }
        for ( int i = st ; i < a.size() ; i++ ) {
            if ( a[i] > target ) break ;
            
            curr.push_back(a[i]) ;
            helper(a , target - a[i] , i , curr , ans ) ;
            curr.pop_back() ;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        // Optimal Approach : Backtracking with repetition and early pruning 
        // TC : O(2 ** N) , SC : O(target) 

        sort ( a.begin() , a.end() ) ;
        vector<vector<int>> ans ;
        vector<int> curr ;
        helper(a , target , 0 , curr , ans) ;
        return ans ;
    }
};
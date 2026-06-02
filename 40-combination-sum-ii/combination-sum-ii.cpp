class Solution {
public:
    // Oracle
    // Microsoft
    // Amazon
    // Adobe
    // Goldman Sachs
    void helper(vector<int>& a , int target , vector<int>& curr , int st , vector<vector<int>>& ans ) {
        if ( target == 0 ) {
            ans.push_back(curr) ;
            return ;
        }

        for ( int i = st ; i < a.size() ; i++ ) {
            if ( i > st && a[i] == a[i - 1] ) continue ;

            if ( a[i] > target ) break ;

            curr.push_back(a[i]) ;
            helper(a , target - a[i] , curr , i + 1 , ans ) ;
            curr.pop_back() ;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort ( a.begin() , a.end() ) ;
        vector<vector<int>> ans ;
        vector<int> curr ;
        helper(a , target , curr , 0 , ans) ;
        return ans ;
    }
};
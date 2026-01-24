class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> p ;
    void helper(vector<int>& a , int t , int st ) {
        if ( t == 0 ) {
            ans.push_back(p) ;
            return ;
        }

        for ( int i = st ; i < a.size() ; i++ ) {
            if ( a[i] > t ) continue ;

            p.push_back(a[i]) ;
            helper( a , t - a[i] , i ) ;
            p.pop_back() ;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        helper(a , t , 0) ;
        return ans ;
    }
};
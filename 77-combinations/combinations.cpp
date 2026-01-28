class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> a ;

    void helper( int st , int n , int k ) {
        if ( a.size() == k ) {
            ans.push_back(a) ;
            return ;
        }

        for ( int i = st ; i <= n ; i++ ) {
            a.push_back(i) ;
            helper(i + 1 , n , k) ;
            a.pop_back() ;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        helper(1 , n , k) ;
        return ans ;
    }
};
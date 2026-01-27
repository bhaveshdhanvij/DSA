class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> path ;

    void helper( int node , vector<vector<int>>& a ) {
        path.push_back(node) ;

        if ( node == a.size() - 1 ) {
            ans.push_back(path) ;
        }else {
            for ( int n : a[node] ) {
                helper(n , a) ;
            }
        }

        path.pop_back() ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& a) {
        helper(0 , a) ;
        return ans ;
    }
};
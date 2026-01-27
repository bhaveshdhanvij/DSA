class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a(n) ;

        for ( auto &e : edges ) {
            a[e[1]].push_back(e[0]) ;
        } 

        vector<int> ans ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( a[i].size() == 0 ) {
                ans.push_back(i) ;
            }
        }

        return ans ;
    }
};
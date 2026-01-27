class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size() + 1 ;
        vector<vector<int>> a(n + 1) ;

        for( auto &e : edges ) {
            a[e[0]].push_back(e[1]) ;
            a[e[1]].push_back(e[0]) ;
        }

        for ( int i = 1 ; i <= n ; i++ ) {
            if ( a[i].size() == n - 1 ) return i ;
        }

        return -1 ;
    }
};
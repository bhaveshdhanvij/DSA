class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> ans ;
        queue<int> q ;
        int c = 0 ;

        vector<int> indeg(n , 0) ;
        vector<vector<int>> a(n) ;

        for ( auto e : p ) {
            a[e[1]].push_back(e[0]) ;
            indeg[e[0]]++ ;
        }

        for ( int i = 0 ; i < n ; i++ ) {
            if ( indeg[i] == 0 ) {
                q.push(i) ;
                ans.push_back(i) ;
            }
        }

        while (!q.empty()) {
            int node = q.front() ;
            q.pop() ;
            c++ ;

            for ( int x : a[node] ) {
                --indeg[x] ;
                if ( indeg[x] == 0 ) {
                    q.push(x) ;
                    ans.push_back(x) ;
                }
            }
        }
        vector<int> t ;
        return c == n ? ans : t ;
    }
};
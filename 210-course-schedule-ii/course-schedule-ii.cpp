class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        // just track the path while applying topological sort 
        vector<int> ans ;
        vector<vector<int>> a(n) ;
        vector<int> indeg(n , 0) ;

        for ( auto x : p ) {
            a[x[1]].push_back(x[0]) ;
            indeg[x[0]]++ ;
        }

        queue<int> q ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( indeg[i] == 0 ) q.push(i) ;
        }

        int count = 0 ;
        while ( !q.empty() ) {
            int curr = q.front() ;
            q.pop() ;

            ans.push_back(curr) ;
            count++ ;

            for ( int x : a[curr] ) {
                --indeg[x] ;
                if (indeg[x] == 0) q.push(x) ;
            }
        }

        vector<int> temp ;
        return count == n ? ans : temp ;
    }
};
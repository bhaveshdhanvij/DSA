class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        // Optimal Approach : Topological sort ie Kahn's Algorithm 
        
        vector<vector<int>> a(n) ;
        vector<int> indeg(n , 0) ;
        
        for ( auto x : p ) {
            a[x[1]].push_back(x[0]) ;
            indeg[x[0]]++ ;
        }

        int c = 0 ;
        queue<int> q ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( indeg[i] == 0 ) q.push(i) ;
        }

        while (!q.empty()) {
            int node = q.front() ;
            q.pop() ;
            c++ ;

            for ( int x : a[node] ) {
                --indeg[x] ;
                if ( indeg[x] == 0 ) q.push(x) ;
            }
        }


        return c == n ;
    }
};
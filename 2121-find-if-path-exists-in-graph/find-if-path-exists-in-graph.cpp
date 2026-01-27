class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> a(n) ;
        
        for ( auto &e : edges ) {
            a[e[0]].push_back(e[1]) ;
            a[e[1]].push_back(e[0]) ;
        }

        vector<bool> vis(n , false) ;
        queue<int> q ;

        q.push(s) ;
        vis[s] = true ;

        while (!q.empty()) {
            int node = q.front() ;
            q.pop() ;

            if ( node == d ) return true ;

            for ( int n : a[node] ) {
                if (!vis[n]) {
                    vis[n] = true ;
                    q.push(n) ;
                }
            }
        }

        return false ;
    }
};
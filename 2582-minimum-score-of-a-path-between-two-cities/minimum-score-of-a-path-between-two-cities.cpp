class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1) ;

        for ( auto x : roads ) {
            adj[x[0]].push_back({x[1] , x[2]}) ;
            adj[x[1]].push_back({x[0] , x[2]}) ;
        }

        vector<int> vis(n + 1 , false) ;
        vis[1] = true ;
        queue<int> q ;
        q.push(1) ;
        
        int ans = INT_MAX ;
        
        while (!q.empty()) {
            int node = q.front() ;
            q.pop() ;

            for ( auto [next , wt] : adj[node] ) {
                ans = min ( ans , wt ) ;

                if (!vis[next] ) {
                    vis[next] = 1 ;
                    q.push(next) ;
                }
            }
        }
        return ans ;
    }
};
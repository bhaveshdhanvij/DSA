class Solution {
public:
    void helper(int node , vector<vector<int>> &adj , vector<bool> &vis , int &nodes , int &deg ) {
        vis[node] = true ;

        nodes++ ;
        deg += adj[node].size() ;

        for ( int v : adj[node] ) {
            if ( !vis[v] ) {
                helper(v , adj , vis , nodes, deg) ;
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ;
        
        for ( auto &e : edges ) {
            adj[e[0]].push_back(e[1]) ;
            adj[e[1]].push_back(e[0]) ;
        }

        int ans = 0 ;
        vector<bool> vis(n , false) ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            if (!vis[i]) {
                int nodes = 0 ;
                int deg = 0 ;
                
                helper(i , adj , vis , nodes , deg) ;
                
                int act = deg / 2 ;
                int req = nodes * (nodes - 1) / 2 ;
                
                if ( act == req ) ans++ ;
            }
        }

        return ans ;
    }
};
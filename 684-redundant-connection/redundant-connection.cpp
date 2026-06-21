class Solution {
public:
    // Microsoft
    // Google
    // Amazon
    // InMobi
    bool helper(int u , int target , vector<vector<int>> &g , vector<bool> &vis ) {
        if ( u == target ) {
            return true ;
        }

        vis[u] = true ;

        for ( int v: g[u] ) {
            if ( !vis[v] && helper(v, target , g , vis)) {
                return true ;
            }
        }

        return false ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Incremental Graph Construction + DFS Connectivity Check
        // TC : O(N * N) , SC : O(N)

        int n = edges.size() ;
        vector<vector<int>> g(n + 1) ; // since it is having one-based indexing 

        for ( auto &e : edges ) {
            int u = e[0] ;
            int v = e[1] ;
            
            vector<bool> vis(n + 1 , false) ;

            if ( helper(u , v , g , vis) ) {
                return e ; // this edge is creating the problem
            }

            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }

        return {} ;
    }
};
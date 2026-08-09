class DSU {
public:
    vector<int> parent , size ;
    DSU (int n) {
        parent.resize(n + 1) ;
        size.resize(n + 1, 1) ;
        for ( int i = 1 ; i <= n ; i++ ) {
            parent[i] = i ;
        }
    }

    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ;
    }

    void unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if (a == b) return ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        DSU dsu(n) ;
        vector<vector<int>> adj(n + 1) ;
        for ( auto &e : d ) {
            int u = e[0] ;
            int v = e[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ; 
        }
        for ( int u = 1 ; u <= n ; u++ ) {
            for (int i = 1 ; i < adj[u].size() ; i++ ) {
                dsu.unite(adj[u][0] , adj[u][i]) ;
            }

            for (int v : adj[u]) {
                if ( dsu.find(u) == dsu.find(v) ) {
                    return false ;
                }
            }
        }
        return true ;
    }
};
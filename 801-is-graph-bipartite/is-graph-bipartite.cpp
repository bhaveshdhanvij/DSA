class DSU {
public:
    vector<int> parent , size ;
    DSU(int n) {
        parent.resize(n) ;
        size.resize(n , 1) ;
        for ( int i = 0 ; i < n ; i++ ) {
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
        if ( a == b ) return ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a;
        size[a] += size[b] ;
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size() ;
        DSU dsu(n) ;
        for ( int u = 0 ; u < n ; u++ ) {
            for ( int i = 1 ; i < g[u].size() ; i++ ) {
                dsu.unite(g[u][0] , g[u][i]) ;
            }
            for ( int v : g[u] ) {
                if ( dsu.find(v) == dsu.find(u) ) {
                    return false ;
                }
            }
        }
        return true ;
    }
};
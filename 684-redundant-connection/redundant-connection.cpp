class DSU {
public:
    vector<int> parent ;
    vector<int> size ;
    DSU(int n) {
        parent.resize(n + 1) ;
        size.resize(n + 1 , 1) ;
        for ( int i = 0 ; i <= n ; i++ ) {
            parent[i] = i ;
        }
    }

    int find(int x) {
        if ( parent[x] == x ) {
            return x ;
        }
        return parent[x] = find(parent[x]) ; // Path compresssion 
    }
    void unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if ( a == b ) return ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size() ;
        DSU dsu(n) ;
        for ( int i = 0 ; i < n ; i++ ) {
            int a = e[i][0] ;
            int b = e[i][1] ;
            a = dsu.find(a) ;
            b = dsu.find(b) ;
            if ( a == b ) return e[i] ;

            dsu.unite(a , b) ;
        }
        return {-1 , -1} ;
    }
};
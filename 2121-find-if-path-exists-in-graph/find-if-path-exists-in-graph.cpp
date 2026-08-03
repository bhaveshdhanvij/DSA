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
        return parent[x] = find(parent[x]) ; // path compresssion 
    }

    void unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if ( a == b ) return ;
        if ( size[a] < size[b] ) swap(a ,b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        DSU dsu(n) ;
        for (auto e : edges) {
            dsu.unite(e[0] , e[1]) ;
        }
        return dsu.find(s) == dsu.find(d) ;
    }
};
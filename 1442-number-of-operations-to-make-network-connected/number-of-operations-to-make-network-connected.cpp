class DSU {
public:
    vector<int> parent , size ;
    DSU(int n) {
        parent.resize(n) ;
        size.resize(n , 1) ;
        for ( int i = 0 ; i < n ; i++ ) parent[i] = i ;
    }

    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ;
    }

    void unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if ( a == b ) return ;
        if( a< b ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& a) {
        if ( a.size() < n - 1 ) return -1 ;
        DSU dsu(n) ;
        for ( auto x : a ) {
            dsu.unite(x[0] , x[1]) ;
        }
        int c = 0 ;
        for (int i = 0 ; i < n ; i++) {
            if ( dsu.find(i) == i ) c++ ;
        }
        return c - 1 ;
    }
};
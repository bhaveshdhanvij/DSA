class DSU {
public:
    vector<int> parent , size ;
    DSU(int n) {
        parent.resize(n + 1) ;
        size.resize(n + 1, 1) ;
        for ( int i = 1 ; i <= n ; i++ ) {
            parent[i] = i ;
        }
    }

    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ; // path compression 
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
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1 ;
        DSU dsu(n) ;
        vector<int> d(n + 1 , 0) ;
        for ( auto e : edges ) {
            d[e[0]]++ ;
            d[e[1]]++ ;
        }
        for ( int i =1 ; i <= n ; i++ ) {
            if ( d[i] == n - 1 ) {
                return i ;
            }
        }
        return -1 ;
    }
};
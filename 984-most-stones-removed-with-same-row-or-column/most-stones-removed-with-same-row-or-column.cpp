class DSU {
public:
    vector<int> parent ;
    vector<int> size ;
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
        parent[b] = a ;
        size[a] += size[b] ;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& a) {
        int n = a.size() ;
        DSU dsu(n) ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                if ( a[i][0] == a[j][0] || a[i][1] == a[j][1] ) {
                    dsu.unite(i , j) ;
                }
            }
        }
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( dsu.find(i) == i ) ans++ ;
        }

        return n - ans ;
    }
};
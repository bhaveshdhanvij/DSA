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
        if ( parent[x] == x ) {
            return x ;
        }
        return parent[x] = find(parent[x]) ; // Path compression 
    }

    void unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if ( a == b ) return ;
        
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += b ;
    }
};

class Solution {
public:
    // Amazon
    // Meta
    // Sprinklr
    // Google
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size() ;
        DSU dsu(n) ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                if ( a[i][j] ) {
                    dsu.unite(i , j) ;
                }
            }
        }
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( dsu.parent[i] == i ) {
                ans++ ;
            }
        }
        return ans ;
    }
};
class DSU {
public:
    vector<int> parent , size ;
    DSU( int n ) {
        parent.resize(n + 1) ;
        size.resize(n + 1 , 1) ;
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
        if ( a == b ) return ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n) ;
        for ( int x = threshold + 1 ; x <= n ; x++ ) {
            for ( int m = 2 * x ; m <= n ; m += x ) {
                dsu.unite(x , m) ;
            }
        }
        vector<bool> ans ;
        for ( auto q : queries) {
            int a = q[0] ;
            int b = q[1] ;
            ans.push_back(dsu.find(a) == dsu.find(b)) ;
        }

        return ans ;
    }
};
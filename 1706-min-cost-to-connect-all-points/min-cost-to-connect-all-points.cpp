class DSU {
public:
    vector<int> parent , size ;
    DSU(int n) {
        parent.resize(n) ;
        size.resize(n , 1) ;
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i ;
        }
    }
    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ;
    }
    bool unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if ( a == b ) return false ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
        return true ;
    }
};
class Solution {
public:
    // DE Shaw
    // Uber
    // Directi
    // Amazon
    // Adobe
    // Microsoft
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size() ;
        vector<tuple<int,int,int>> edges ;
        for (int i = 0 ; i < n ; i++) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                int cost = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]) ;
                edges.push_back({cost , i , j}) ;
            }
        }
        sort(edges.begin() , edges.end()) ;
        DSU dsu(n) ;
        int ans = 0 , used = 0 ;
        for ( auto [cost , u , v] : edges ) {
            if ( dsu.unite(u , v) ) {
                ans += cost ;
                used++ ;
                if ( used == n - 1 ) break ;
            }
        }
        return ans ;
    }
};
class DSU {
public:
    vector<int> parent ;
    vector<int> sz ;
    DSU(int n) {
        parent.resize(n) ;
        sz.resize(n , 1) ;
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
        if ( sz[a] < sz[b] ) swap(a , b) ;
        parent[b] = a ;
        sz[a] += sz[b] ;
    }
};
class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        unordered_map<int,int> x_map , y_map ;
        int x_id = 0 , y_id = 0 ;
        for ( auto p : points ) {
            if (!x_map.count(p[0]) ) x_map[p[0]] = x_id++ ;
            if (!y_map.count(p[1]) ) y_map[p[1]] = y_id++ ;
        }
        DSU dsu(x_id + y_id) ;
        for ( auto p : points ) {
            int u = x_map[p[0]] ;
            int v = y_map[p[1]] + x_id ;
            dsu.unite(u , v) ;
        }        
        unordered_map<int,int> mp ;
        set<int> vis ;
        for ( auto p : points ) {
            int root = dsu.find(x_map[p[0]]) ;
            mp[root]++ ;
        }
        vector<int> temp ;
        for ( auto p : mp ) {
            temp.push_back(p.second) ;
        }
        sort(temp.rbegin() , temp.rend()) ;
        if ( temp.size() >= 2 ) return temp[0] + temp[1] + 1 ;
        else if (temp.size() == 1) return temp[0] + 1 ;
        return 1 ;
    }
};
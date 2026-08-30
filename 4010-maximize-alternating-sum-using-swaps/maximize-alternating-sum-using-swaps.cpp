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
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ; 
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a, vector<vector<int>>& swaps) {
        int n = a.size() ;
        DSU dsu(n) ;
        for ( auto x : swaps ) {
            dsu.unite(x[0] , x[1]) ;
        }

        vector<vector<int>> values(n) ;
        unordered_map<int,int> mp ;

        for ( int i = 0 ; i < n ; i++ ) {
            int root = dsu.find(i) ;
            values[root].push_back(a[i]) ;
            if ( i % 2 == 0 ) {
                mp[root]++ ;
            }
        }

        long long ans = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( values[i].empty() ) continue ;

            auto v = values[i] ;
            sort(v.begin() , v.end()) ;
            int k = mp[i] ;
            for ( int i = 0 ; i < (int)v.size() - k ; i++ ) ans -= v[i] ;
            for ( int i = (int)v.size() - k ; i < (int)v.size() ; i++ ) ans += v[i] ;
        }

        return ans ;
    }
};
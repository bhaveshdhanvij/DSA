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
    int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& swaps) {
        int n = a.size() ;
        DSU dsu(n) ;
        for ( auto s : swaps ) {
            dsu.unite(s[0] , s[1]) ;
        }
        unordered_map<int,vector<int>> gp ;
        for ( int i = 0 ; i < n ; i++ ) {
            gp[dsu.find(i)].push_back(i) ;
        }

        int ans = 0 ;
        for ( auto p : gp ) {
            vector<int> t = p.second ;
            unordered_map<int,int> mp ;
            for ( int idx : t ) {
                mp[a[idx]]++ ;
            }
            for (int idx : t) {
                if ( mp[b[idx]] > 0 ) mp[b[idx]]-- ;
                else ans++ ;
            }
        }

        return ans ;
    }
};
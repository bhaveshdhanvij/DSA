class DSU {
public:
    vector<int> parent ;
    vector<int> sz ;
    DSU(int n) {
        parent.resize(n) ;
        sz.resize(n , 1) ;
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
        if ( sz[a] < sz[b] ) swap(a , b) ;
        parent[b] = a ;
        sz[a] += sz[b] ;
    }
};

class Solution {
public:
    bool helper(string s , string t) {
        if ( s.size() != t.size() ) return false ;
        vector<int> d ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] != t[i] ) d.push_back(i) ;
        }
        if ( d.empty() ) return true ;
        if ( d.size() != 2 ) return false ;
        int i = d[0] ;
        int j = d[1] ;
        return s[i] == t[j] && s[j] == t[i] ;
    }
    int numSimilarGroups(vector<string>& a) {
        int n = a.size() ;
        DSU dsu(n) ;
        for ( int i = 0 ; i < n ; i++ ) {
            string s = a[i] ;
            for ( int j = i + 1 ; j < n ; j++ ) {
                string t = a[j] ;
                if ( helper(s , t) ) {
                    dsu.unite(i , j) ;
                }
            }
        }

        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( dsu.find(i) == i ) ans++ ;
        }

        return ans ;
    }
};
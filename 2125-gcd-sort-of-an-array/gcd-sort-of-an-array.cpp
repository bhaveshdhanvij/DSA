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
    vector<int> helper(int x) {
        vector<int> ans ;
        for ( int i = 2 ; i * i <= x ; i++ ) {
            if ( x % i == 0 ) {
                ans.push_back(i) ;
                x /= i ;
                while ( x % i == 0 ) {
                    ans.push_back(i) ;
                    x /= i ;
                }
            }
        }
        if ( x > 1 ) ans.push_back(x) ;
        return ans ;
    }
    bool gcdSort(vector<int>& a) {
        int n = a.size() ;
        DSU dsu(n) ;

        unordered_map<int,int> mp ; // prime factors => first element's idx having that factor
        for (int i = 0 ; i < n ; i++ ) {
            vector<int> f = helper(a[i]) ;
            for ( int p : f ) {
                if ( mp.count(p) ) {
                    dsu.unite(i , mp[p]) ;
                }else {
                    mp[p] = i ;
                }
            }
        }

        vector<int> b = a ;
        sort(b.begin() , b.end()) ;
        
        unordered_map<int,vector<int>> indices ;
        for (int i = 0 ; i < n ; i++) {
            indices[a[i]].push_back(i) ;
        }

        unordered_map<int,int> ptr ;
        for (int i = 0 ; i < n ; i++) {
            int idx = indices[b[i]][ptr[b[i]]++] ;
            if ( dsu.find(i) != dsu.find(idx) ) {
                return false ;
            }
        }

        return true ;
    }
};
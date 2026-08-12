class DSU {
public:
    vector<int> parent , size ;
    DSU (int n) {
        parent.resize(n) ;
        size.resize(n , 1) ;
        for ( int i = 0 ; i < n ; i++ ) parent[i] = i ;
    }

    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ;
    }

    bool unite(int a , int b) {
        a = find(a) ;
        b = find(b) ;
        if (a == b) return false ;
        if ( size[a] < size[b] ) swap(a , b) ;
        parent[b] = a ;
        size[a] += size[b] ;
        return true ;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& a) {
        int n = a.size() ;
        DSU dsu(n * n) ;
        int delRow[4] = {-1 , 0 , 1 , 0} ;
        int delCol[4] = {0 , 1 , 0 , -1} ;
        
        for ( int r = 0 ; r < n ; r++ ) {
            for ( int c = 0 ; c < n ; c++ ) {
                if ( a[r][c] == 0 ) continue ;


                int id = r * n + c ;
                for ( int i = 0 ; i < 4 ; i++ ) {
                    int nr = r + delRow[i] ;
                    int nc = c + delCol[i] ;
                    if ( nr < 0 || nr >= n || nc < 0 || nc >= n ) continue ;
                    if ( a[nr][nc] == 1 ) {
                        int nid = nr * n + nc ;
                        dsu.unite(id , nid) ;
                    }
                }
            }
        }
        int ans = 0 ;
        for (int r = 0; r < n ; r++) {
            for ( int c = 0 ; c < n ; c++) {
                if ( a[r][c] == 1 ) {
                    ans = max ( ans , dsu.size[dsu.find(r * n + c)]) ;
                }
            }
        }

        for ( int r = 0 ; r < n ; r++) {
            for (int c = 0 ; c < n ; c++) {
                if ( a[r][c] == 1 ) continue ;

                unordered_set<int> s ;
                int curr = 1 ;

                for ( int i = 0 ; i < 4 ; i++ ) {
                    int nr = r + delRow[i] ;
                    int nc = c + delCol[i] ;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n ) continue ;
                    if ( a[nr][nc] == 0 ) continue ;

                    int nid = nr * n + nc ;
                    int root = dsu.find(nid) ;
                    
                    if ( s.insert(root).second) {
                        curr += dsu.size[root] ;
                    }
                }
                ans = max ( ans , curr ) ;
            }
        }
        return ans ;
    }
};
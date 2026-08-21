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
    int connected(int a , int b) {
        return find(a) == find(b) ;
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& a) {
        int n = a.size() , m = a[0].size() ;
        DSU dsu(m * n + 1) ;
        int dummy = m * n ;
        int delRow[4] = {-1 , 0 , 1 , 0} ;
        int delCol[4] = {0 , 1 , 0 , -1} ;
        for ( int r = 0 ; r < n ; r++ ) {
            for ( int c = 0 ; c < m ; c++ ) {
                if ( a[r][c] != 'O' ) continue ;
                int curr = r * m + c ;
                if ( r == 0 || r == n - 1 || c == 0 || c == m - 1 ) {
                    dsu.unite(dummy , curr) ;
                }

                for (int k = 0 ; k < 4 ; k++) {
                    int nr = r + delRow[k] ;
                    int nc = c + delCol[k] ;
                    if ( nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == 'O' ) {
                        int next = nr * m + nc ;
                        dsu.unite(curr , next) ;
                    } 
                }
            }
        }
        for (int r = 0 ; r < n ; r++ ) {
            for ( int c = 0 ; c < m ; c++ ) {
                if ( a[r][c] == 'O' ) {
                    int curr = r * m + c ;
                    if ( !dsu.connected(curr , dummy) ) {
                        a[r][c] = 'X' ;
                    }
                }
            }
        }
    }
};
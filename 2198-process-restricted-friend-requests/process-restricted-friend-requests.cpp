class DSU {
public:
    vector<int> parent , size ;
    DSU(int n) {
        parent.resize(n) ;
        size.resize(n , 1) ;
        for (int i = 0 ; i < n ; i++) {
            parent[i] = i ;
        }
    }
    int find(int x) {
        if ( parent[x] == x ) return x ;
        return parent[x] = find(parent[x]) ;
    }

    void unite(int a, int b) {
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu(n) ;
        vector<bool> ans ;
        for ( auto& r : requests ) {
            int a = r[0] ;
            int b = r[1] ;

            a = dsu.find(a) ;
            b = dsu.find(b) ;
            
            bool flag = true ;
            for ( auto &res : restrictions) {
                int x = res[0] ;
                int y = res[1] ;
                
                x = dsu.find(x) ;
                y = dsu.find(y) ;

                if ( (a == x && b == y) || (a == y && b == x) ) {
                    flag = false ;
                    break ;
                }
            }

            if ( flag ) {
                dsu.unite(a , b) ;
                ans.push_back(true) ;
            }else {
                ans.push_back(false) ;
            }
        }
        return ans ;
    }
};
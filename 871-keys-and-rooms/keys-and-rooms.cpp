class Solution {
public:
    void dfs ( int idx , vector<vector<int>>&a , vector<bool>& vis) {
        vis[idx] = true ;

        auto &vec = a[idx] ;

        for ( int i = 0 ; i < vec.size() ; i++ ) {
            if ( !vis[vec[i]] ) {
                dfs(vec[i] , a , vis) ;
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& a) {
        int n = a.size() ;

        vector<bool> vis(n , false) ;
        
        vis[0] = true ;

        dfs( 0 , a , vis ) ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( !vis[i] ) return false ;
        }

        return true ;
    }
};
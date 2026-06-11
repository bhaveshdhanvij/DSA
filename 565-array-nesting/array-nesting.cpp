class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int n = a.size() ;
        vector<bool> vis(n , false) ;
        
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( vis[i] ) continue ;

            int idx = i , cnt = 0 ;
            while ( !vis[idx] ) {
                vis[idx] = true ;
                idx = a[idx] ;
                cnt++ ;
            }

            ans = max ( ans , cnt ) ;
        }

        return ans ;
    }
};
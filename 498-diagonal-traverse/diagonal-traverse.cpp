class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        map<int,vector<int>> mp ;
        int m = a.size() , n = a[0].size() ;

        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                int k = i + j ;
                mp[k].push_back(a[i][j]) ;
            } 
        }

        vector<int> ans ;
        for ( int i = 0 ; i < mp.size() ; i++ ) {
            auto v = mp[i] ;
            if ( i % 2 == 0 ) {
                reverse( v.begin() , v.end() ) ;  
            }
            for ( int x : v ) {
                ans.push_back(x) ;
            }
        }

        return ans ;
    }
};
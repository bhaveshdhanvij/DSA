class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size() , m = b.size() ;
        int i = 0 , j = 0 ;
        vector<vector<int>> ans ;
        while ( i < n || j < m ) {
            int t ;
            if ( i == n ) {
                t = b[j][0] ;
            }else if ( j == m ) {
                t = a[i][0] ;
            }else {
                t = min(a[i][0] , b[j][0]) ;
            }

            while ( i < n && a[i][0] < t ) i++ ;
            while ( j < m && b[j][0] < t ) j++ ;

            int x = (i < n) ? a[i][1] : 0 ;
            int y = (j < m) ? b[j][1] : 0 ;
            
            ans.push_back({t , x + y}) ;

            if ( i < n && a[i][0] == t ) i++ ;

            if ( j < m && b[j][0] == t ) j++ ;
        }
        return ans ;
    }
};
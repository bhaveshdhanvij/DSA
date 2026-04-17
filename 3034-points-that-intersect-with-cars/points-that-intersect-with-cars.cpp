class Solution {
public:
    int numberOfPoints(vector<vector<int>>& a) {
        vector<vector<int>> ans ;
        sort ( a.begin() , a.end() ) ;
        
        ans.push_back(a[0]) ;
        for ( int i = 1 ; i < a.size() ; i++ ) {
            int st = a[i][0] ;
            int end = a[i][1] ;
            if ( st > ans.back()[1] ) {
                ans.push_back({st , end}) ;
            }else {
                ans.back()[1] = max ( ans.back()[1] , end ) ;
            }
        }

        int p = 0 ;
        for ( auto x : ans ) {
            p += x[1] - x[0] + 1 ;
        }

        return p ;
    }
};
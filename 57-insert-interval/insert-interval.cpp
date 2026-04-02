class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
        a.push_back(ni) ;
        int n = a.size() ;
        vector<vector<int>> ans ;
        sort ( a.begin() , a.end() ) ;
        
        ans.push_back(a[0]) ;
        for ( int i = 1 ; i < n ; i++ ) {
            int st = a[i][0] ;
            int end = a[i][1] ;
            if ( ans.back()[1] < st ) {
                ans.push_back(a[i]) ;
            }else {
                ans.back()[1] = max ( ans.back()[1] , end ) ;
            }
        }

        return ans ;
    }
};
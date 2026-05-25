class Solution {
public:
    // Google
    vector<vector<int>> merge(vector<vector<int>>& a) {
        // Optimal Approach : Sorting + Greedy 
        // TC : O(Nlog(N)) , SC : O(1) 

        int n = a.size() ;
        sort ( a.begin() , a.end() ) ;
        vector<vector<int>> ans ;
        ans.push_back(a[0]) ;
        for ( int i = 1 ; i < n ; i++ ) {
            int st = a[i][0] ;
            int end = a[i][1] ;
            if ( st > ans.back()[1] ) {
                ans.push_back(a[i]) ;
            }else {
                ans.back()[1] = max ( ans.back()[1] , end ) ;
            }
        }
        return ans ;
    }
};
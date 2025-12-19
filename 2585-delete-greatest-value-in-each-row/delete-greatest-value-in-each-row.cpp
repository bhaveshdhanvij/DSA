class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& a) {
        for ( int i = 0 ; i < a.size() ; i++ ) {
            sort ( a[i].begin() , a[i].end() ) ;
        }
        int ans = 0 ;
        for ( int i = 0 ; i < a[0].size() ; i++ ) {
            int maxx = INT_MIN ;
            for ( int j = 0 ; j < a.size() ; j++ ) {
                maxx = max ( maxx , a[j][i] ) ;
            }
            ans += maxx ;
        }
        return ans ;
    }
};
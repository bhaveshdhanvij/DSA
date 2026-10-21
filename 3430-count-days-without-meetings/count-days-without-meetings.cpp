class Solution {
public:
    int countDays(int d, vector<vector<int>>& a) {
        sort(a.begin() , a.end()) ;
        int ans = a[0][0] - 1 ;
        int end = a[0][1] ;
        for ( int i = 1 ; i < a.size() ; i++ ) {
            if ( a[i][0] > end ) {
                ans += a[i][0] - end - 1 ;
            }
            end = max ( end , a[i][1] ) ;
        }
        ans += d - end ;
        return ans ;
    }
};
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& a) {
        int n = a.size() ;
        sort(a.begin() , a.end()) ;
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                if ( a[i][1] >= a[j][0] ) ans++ ;
            }
        }
        return ans ;
    }
};
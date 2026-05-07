class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums ) {
        int n = nums.size() ;
        // sort ( nums.begin() , nums.end() ) ;

        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            bool flag = false ;
            int a = nums[i][0] , b = nums[i][1] ;
            for ( int j = 0 ; j < n ; j++ ) {
                if ( i == j ) continue ;
                int c = nums[j][0] , d = nums[j][1] ;
                if ( c <= a && b <= d ) {
                    flag = true ;
                    break ;
                }
            }
            if ( flag ) ans++ ;
        }

        return n - ans ;
    }
};
class Solution {
public:
    int maxArea(vector<int>& a) {
        // brute force solution TC : O(N*N) || SC : O(1) ;

        // int n = a.size() ;
        // int ans = 0 ;

        // for ( int i = 0 ; i < n - 1 ; i++ ) {
        //     for ( int j = i + 1 ; j < n ; j++ ) {
        //         int h = min ( a[i] , a[j] ) ;
        //         int w = j - i ;
                
        //         int curr = h * w ;
                
        //         ans = max ( ans , curr ) ;
        //     }
        // }

        // return ans ;


        // Optimal Approach : Two pointer Approach TC : O(N) | SC : O(1) ;

        int n = a.size() ;
        int i = 0 , j = n - 1 ;

        int ans = 0 ;
        
        while ( i < j ) {
            int h = min ( a[i] , a[j] ) ;
            int w = j - i ;

            int curr = h * w ;

            ans = max ( ans , curr ) ;

            if ( a[i] <= a[j] ) i++ ;
            else j-- ;
        }

        return ans ;
    }
};
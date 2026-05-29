class Solution {
public:
    int trap(vector<int>& a) {
        // Naive Approach : Using 2 for loops for calculating leftmax and rightmax 
        // TC : O(N * N) , SC : O(1) 

        // int n = a.size() ;
        // int ans = 0 ;
        // for ( int i = 1 ; i < n - 1 ; i++ ) {
        //     int lmax = a[i] ;
        //     for ( int j = i - 1 ; j >= 0 ; j-- ) {
        //         lmax = max ( lmax , a[j] ) ;
        //     }
        //     int rmax = a[i] ;
        //     for ( int j = i + 1 ; j < n ; j++ ) {
        //         rmax = max ( rmax , a[j] ) ;
        //     }
        //     ans += min ( rmax , lmax ) - a[i] ;
        // }

        // return ans ;


        // Approach 2 : Using Precomputed left and right max arrays 
        // TC : O(N) , SC : O(N) 

        // int n = a.size() ;
        // int ans = 0 ;
        // int lmax[n] ;
        // lmax[0] = a[0] ;
        // for ( int i = 1 ; i < n ; i++ ) {
        //     lmax[i] = max ( a[i] , lmax[i - 1] ) ;
        // }
        // int rmax[n] ;
        // rmax[n - 1] = a[n - 1] ;
        // for ( int i = n - 2 ; i >= 0 ; i-- ) {
        //     rmax[i] = max ( a[i] , rmax[i + 1] ) ;
        // }
        // for ( int i = 1 ; i < n - 1 ; i++ ) {
        //     ans += min( rmax[i] , lmax[i] ) - a[i] ;
        // }
        // return ans ;


        // Optimal Approach : 2-pointer Approach 
        // TC : O(N) , SC : O(1) 

        int n = a.size() , ans = 0 ;
        int lmax = a[0] , rmax = a[n - 1] ;
        int low = 1 , high = n - 2 ;
        while ( low <= high ) {
            lmax = max ( lmax , a[low] ) ;
            rmax = max ( rmax , a[high] ) ;

            if ( lmax <= rmax ) {
                ans += lmax - a[low++] ;
            }else {
                ans += rmax - a[high--] ;
            }
        }

        return ans ;
    }
};
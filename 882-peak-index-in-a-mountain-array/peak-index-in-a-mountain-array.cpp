class Solution {
public:
    // Google
    // DE Shaw
    // Meta
    // Amazon
    // Microsoft
    // Adobe
    // Accenture
    // TCS
    int peakIndexInMountainArray(vector<int>& a) {
        // Naive Approach : Linear search to find the peak 
        // TC : O(N) , SC : O(1) 

        // int n = a.size() ;
        // int idx = 0 , maxx = a[0] ;
        // for ( int i = 1 ; i < n ; i++ ) {
        //     if ( a[i] > maxx ) {
        //         maxx = a[i] ;
        //         idx = i ;
        //     }
        // }
        // return idx ;


        // Optimal Approach : Using binary search 
        // TC : O(log(N)) , SC : O(1)

        int n = a.size() ;
        int l = 0 , r = n - 1 ;
        while ( l < r ) {
            int mid = l + (r - l) / 2 ;
            if ( a[mid] < a[mid + 1] ) {
                l = mid + 1 ;
            }else {
                r = mid ;
            }
        }
        return l ;
    }
};
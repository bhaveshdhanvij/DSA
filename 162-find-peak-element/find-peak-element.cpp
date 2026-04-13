class Solution {
public:
    int findPeakElement(vector<int>& a) {
        // track whether the element is in increasing or decreasing curve 
        int n = a.size() ;

        if ( n == 1 ) return 0 ;
        if ( a[0] > a[1] ) return 0 ;
        if ( a[n - 1] > a[n - 2] ) return n - 1 ;

        int l = 1 , h = n - 2 ;
        while ( l <= h ) {
            int mid = ( l + h ) / 2 ;
            if ( a[mid] > a[mid - 1] && a[mid] > a[mid + 1] ) {
                return mid ;
            }else if ( a[mid] > a[mid - 1] ) {
                l = mid + 1 ;
            }else {
                h = mid - 1 ;
            }
        }

        return -1 ;
    }
};
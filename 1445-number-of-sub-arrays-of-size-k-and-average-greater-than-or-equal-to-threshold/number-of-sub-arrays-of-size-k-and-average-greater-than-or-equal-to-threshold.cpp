class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0 ;
        double sum = 0 , l = 0 ;
        int n = arr.size() ;
        for ( int r = 0 ; r < n ; r++ ) {
            sum += arr[r] ;
            if ( r - l + 1 == k ) {
                double avg = sum / k ;
                if ( avg >= threshold ) ans++ ;
                sum -= arr[l++] ;
            }
        }
        return ans ;
    }
};
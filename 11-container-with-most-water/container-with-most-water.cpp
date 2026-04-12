class Solution {
public:
    int maxArea(vector<int>& a) {
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
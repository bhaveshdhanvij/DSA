class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        // Sliding Window approach TC : O(NlogN) 

        int n = a.size() ;
        int mx = 0 , l = 0 ;

        sort ( a.begin() , a.end() ) ; // to able to track min and max in current window  

        for ( int r = 0 ; r < n ; r++ ) {
            while ( a[r] > (long long) k * a[l] ) {
                l++ ; // invalid 
            }

            mx = max ( mx , r - l + 1 ) ;
        }

        return n - mx ;
    }
};
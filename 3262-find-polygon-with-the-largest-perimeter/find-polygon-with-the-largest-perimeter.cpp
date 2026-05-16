class Solution {
public:
    long long largestPerimeter(vector<int>& a) {
        // TC : O(Nlog(N)) , SC : o(1)
        int n = a.size() ;
        long long sum = 0 ;
        sort ( a.begin() , a.end() ) ;

        for ( auto x : a ) sum += x ;

        for ( int k = n - 1 ; k >= 2 ; k-- ) {
            long long r = sum - a[k] ;
            if ( r > a[k] ) {
                return sum ;
            }

            sum -= a[k] ;
        }

        return -1 ;
    }
};
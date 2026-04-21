class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        long long curr = 0 , ans = 0 ;
        for ( auto x : a ) {
            int arr = x[0] ;
            int dur = x[1] ;

            curr = max ( curr , (long long)arr ) ;
            curr += dur ;
            ans += (curr - arr) ;
        }

        return (double)ans / a.size() ;
    }
};
class Solution {
public:
    long long maxPairStrength(vector<int>& a) {
        int n = a.size() ;
        long long ans = 0 ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            for ( int j = i + 1 ; j < a.size() ; j++ ) {
                long long d = 1LL * gcd(a[i] , a[j]) ;
                long long curr = 1LL * ((1LL *a[i] * a[j]) / (1LL * d * d)) ;
                ans = max ( ans , curr ) ;
            }
        }
        return ans ;
    }
};
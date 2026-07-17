class Solution {
public:
    const int mod = 1000000007 ;
    int helper(int n)  {
        if ( n <= 1 ) return false ;
        for ( int i = 2 ; i * i <= n ; i++ ) {
            if ( n % i == 0 ) {
                return false ;
            }
        }
        return true ;
    }
    
    long long f (int n) {
        long long ans = 1 ;
        for ( int i = 2 ; i <= n ; i++ ) {
            ans = (ans * i) % mod ;
        }
        return ans ;
    }
    int numPrimeArrangements(int n) {
        int c = 0 ;
        for ( int i = 2 ; i <= n ; i++ ) {
            if ( helper(i) ) c++ ;
        }
        return (f(c) * f(n - c)) % mod ;
    }
};
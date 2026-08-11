class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n = s.size() ;
        long long hash = 0 ;
        long long powerk = 1 ;
        for ( int i = 0 ; i < k ; i++ ) {
            powerk = powerk * power % mod ;
        }
        int ans = 0 ;
        for ( int i = n - 1 ; i >= 0 ; i-- ) {
            hash = (hash * power + (s[i] - 'a' + 1)) % mod ;
            if ( i + k < n ) {
                hash = (hash - (s[i + k] - 'a' + 1) * powerk % mod + mod) % mod ;
            }
            if ( i + k <= n && hash == hashValue ) {
                ans = i ;
            }
        }

        return s.substr(ans , k) ;
    }
};
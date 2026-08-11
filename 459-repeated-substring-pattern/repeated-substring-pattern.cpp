class RollingHash {
    using ll = long long ;
    
    static const ll mod = 1e9 + 7 ;
    static const ll base = 911382323 ;
    
    vector<ll> power , pref ;
public:
    RollingHash(const string& s) {
        int n = s.size() ;
        pref.resize(n + 1 , 0) ;
        power.resize(n + 1 , 1) ;
        for ( int i = 0 ; i < n ; i++ ) {
            pref[i + 1] = (pref[i] * base + s[i]) % mod ;
            power[i + 1] = (power[i] * base) % mod ;
        }
    }

    ll get(int l , int r) {
        return (pref[r + 1] - pref[l] * power[r - l + 1] % mod + mod) % mod ;
    }
};
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size() ;
        RollingHash rh(s) ;
        for ( int len = 1 ; len < n ; len++ ) {
            if (n % len != 0 ) continue ;
            long long target = rh.get(0 , len - 1) ;
            bool flag = true ;
            for ( int i = len ; i < n ; i += len ) {
                if ( rh.get(i , i + len - 1) != target ) {
                    flag = false ;
                    break ;
                }
            }
            if ( flag ) return true ;
        }
        return false ;
    }
};
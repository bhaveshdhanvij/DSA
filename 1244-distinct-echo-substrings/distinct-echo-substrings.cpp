class RollingHash {
    using ll = long long ;

    static const ll mod = 1e9 + 7 ;
    static const ll base = 911382323 ;
    
    vector<ll> pref , power ;

public:
    RollingHash(const string& s) {
        int n = s.size() ;
        pref.resize(n + 1, 0) ;
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
    int distinctEchoSubstrings(string s) {
        int n = s.size() ;
        RollingHash rh(s) ;
        unordered_set<long long> ss ;
        for (int len = 1 ; 2 * len <= n ; len++ ) {
            for ( int l = 0 ; l + 2 * len <= n ; l++ ) {
                int mid = l + len ;
                int r = l + 2 * len ;

                long long a = rh.get(l , mid - 1) ;
                long long b = rh.get(mid , r - 1) ;
                if ( a == b ) ss.insert(a) ;
            }
        }
        return ss.size() ;
    }
};
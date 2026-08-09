class RollingHash {
private:
    using ll = long long ;
    static const ll mod = 1e9 + 7 ;
    static const ll base = 911382323 ;
    vector<ll> pref , power ;
public:
    RollingHash(const string& s) {
        int n = s.size() ;
        pref.resize(n + 1 , 0) ;
        power.resize(n + 1 , 1) ;

        for ( int i = 0 ; i < n ; i++ ) {
            power[i + 1] = power[i] * base % mod ;
            pref[i + 1] = (pref[i] * base + (s[i] - 'a' + 1)) % mod ;
        }
    }

    ll get(int l , int r) {
        if ( l > r ) return 0 ;
        return ( pref[r + 1] - pref[l] * power[r - l + 1] % mod + mod) % mod ;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        int n = a.size() ;
        if ( n == 0 ) return "" ;
        int minn = INT_MAX ;
        for ( string s : a ) minn = min ( minn , (int)s.size()) ;
        
        vector<RollingHash> hashes ;
        for ( const string& s : a ) {
            hashes.emplace_back(s) ;
        }

        auto check = [&](int len){
            if ( len == 0 ) return true ;
            
            long long t = hashes[0].get(0 , len - 1) ;
            for ( int i = 1 ; i < n ; i++ ) {
                long long curr = hashes[i].get(0 , len - 1) ;
                if ( curr != t ) {
                    return false ;
                }
            }
            return true ;
        };

        int l = 0 , h = minn ;
        while ( l < h ) {
            int mid = l + (h - l + 1) / 2 ;
            if ( check(mid) ) {
                l = mid ;
            }else {
                h = mid - 1 ;
            }
        }

        return a[0].substr(0 , l) ;
    }
};
class Solution {
public:
    string helper(long long n) {
        if ( n == 0 ) return "0" ;
        string ans = "" ;
        string mp = "0123456789ABCDEF" ;
        while ( n > 0 ) {
            ans += mp[n % 16] ;
            n /= 16 ;
        }
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }

    string helper2(long long n) {
        if ( n == 0 ) return "0" ; 
        string ans = "" ;
        string mp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
        while ( n > 0 ) {
            ans += mp[n % 36] ;
            n /= 36 ;
        }
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
    string concatHex36(int n) {
        long long sq = 1LL * n * n ;
        long long cube = sq * n ;
        return helper(sq) + helper2(cube) ;
    }
};
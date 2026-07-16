class Solution {
public:
    string toHex(int num) {
        if ( num == 0 ) return "0" ;
        string mp = "0123456789abcdef" ;
        string ans = "" ;
        unsigned int n = num ;
        while ( n > 0 ) {
            int idx = n % 16 ;
            ans += mp[idx] ;
            n /= 16 ;
        } 
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size() ;
        unordered_map<char,int> mp ;
        int l = 0 ;
        for ( int r = 0 ; r < n ; r++ ) {
            mp[s[r]]++ ;
            if ( r - l + 1 == k ) {
                if ( mp.size() == 1 ) {
                    if ( !( (l > 0 && s[l - 1] == s[l]) || (r < n - 1 && s[r + 1] == s[r]) ) ) {
                        return true ;
                    }
                }
                mp[s[l]]-- ;
                if ( mp[s[l]] == 0 ) mp.erase(s[l]) ;
                l++ ;
            }
        }

        return false ;
    }
};
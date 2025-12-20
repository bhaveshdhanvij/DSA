class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp ;
        int n = s.size() ;
        int l = 0 ;
        int ans = INT_MIN ;
        for ( int r = 0 ; r < n ; r++ ) {
            mp[s[r]]++ ;
            if ( mp.size() != (r - l + 1) ) {
                mp[s[l]]-- ;
                if ( mp[s[l]] == 0 ) mp.erase(s[l]) ;
                l++ ;
            }
            ans = max ( ans , r - l + 1 ) ;
        }
        return ans == INT_MIN ? 0 : ans ;
    }
};
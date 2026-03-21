class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // TC : O(N) , SC : O(26) 
        int n = s.length() ;
        int ans = 0 , l = 0 ;
        unordered_map<char,int> mp ;
        for ( int r = 0 ; r < n ; r++ ) {
            while ( mp[s[r]] > 0 ) {
                mp[s[l]]-- ;
                l++ ;
            }
            mp[s[r]]++ ;
            ans = max ( ans , r - l + 1 ) ;
        }
        return ans ;
    }
};
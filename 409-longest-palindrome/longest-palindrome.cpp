class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp ;
        for ( char c : s ) mp[c]++ ;
        int ans = 0 ;
        bool flag = false ;
        for ( auto p : mp ) {
            if ( p.second % 2 == 0 ) {
                ans += p.second ;
            }else {
                ans += p.second - 1 ;
                flag = true ;
            }
        }
        if ( flag ) ans++ ;
        return ans ;
    }
};
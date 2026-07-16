class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0 ;
        for ( char c : s ) {
            int x = c - 'A' + 1 ;
            ans = ans * 26 + x ;
        }
        return ans ;
    }
};
class Solution {
public:
    bool squareIsWhite(string c) {
        int ans = ( c[0] - 'a' + 1 ) + (c[1] - '0') ;
        return ans % 2 == 1 ;
    }
};
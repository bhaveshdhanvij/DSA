class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0 ;
        int curr = 1 ;
        while ( n >= curr ) {
            n -= curr ;
            curr++ ;
            ans++ ;
        }
        return ans ;
    }
};
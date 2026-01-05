class Solution {
public:
    int integerReplacement(unsigned int n) {
        unsigned int ans = 0 ;
        while ( n != 1 ) {
            if ( n % 2 == 0 ) {
                n /= 2 ;
            }else {
                return 1 + ans + min( integerReplacement(n - 1) , integerReplacement(n + 1) ) ;
            }
            ans++ ;
        }
        return ans ;
    }
};
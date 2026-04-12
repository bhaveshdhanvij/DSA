class Solution {
public:
    int passThePillow(int n, int t) {
        t = t % (2 * (n - 1)) ;
        int curr = 1 ;
        int d = -1 ;

        while ( t-- ) {
            if ( curr == 1 || curr == n ) d *= -1 ;
            curr += d ;
        }

        return curr ;
    }
};
class Solution {
public:
    int helper(int n , int t) {
        int p = 1 ;
        while ( n > 0 ) {
            int r = n % 10 ;
            p *= r ;
            n /= 10 ;
        }
        return p % t == 0 ;
    }
    int smallestNumber(int n, int t) {
        while (!helper(n , t)) n++ ;
        return n ;
    }
};
class Solution {
public:
    int maxProduct(int n) {
        int a = -1 , b = -1 ;
        int temp = n ;
        while ( temp > 0 ) {
            int d = temp % 10 ;
            if ( d > a ) {
                b = a ;
                a = d ;
            }else if ( d > b ) {
                b = d ;
            }
            temp /= 10 ;
        }
        return a * b ;
    }
};
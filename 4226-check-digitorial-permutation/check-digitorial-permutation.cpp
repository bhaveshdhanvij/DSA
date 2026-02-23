class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> f(10 , 1) ;
        for ( int i = 1 ; i <= 9 ; i++ ) f[i] = i * f[i - 1] ;

        unordered_map<int,int> a ;
        int sum = 0 , t = n ;
        while ( t > 0 ) {
            int r = t % 10 ;
            sum += f[r] ;
            a[r]++ ;
            t /= 10 ;
        }

        unordered_map<int,int> b ;
        while ( sum > 0 ) {
            int r = sum % 10 ;
            b[r]++ ;
            sum /= 10 ;
        }

        return a == b ;
    }
};
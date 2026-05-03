class Solution {
public:
    int rev ( int n ) {
        int temp = n , rev = 0 ;
        while ( temp ) {
            int r = temp % 10 ;
            rev = rev * 10 + r ;
            temp /= 10 ;
        }
        return rev ;
    }
    
    bool prime(int n ) {
        if ( n <= 1 ) return false ;
        for ( int i = 2 ; i * i <= n ; i++ ) {
            if ( n % i == 0 ) {
                return false ;
            }
        }
        return true ;
    }

    int sumOfPrimesInRange(int n) {
        vector<int> a(1001 , 0) ;

        for ( int i = 2 ; i <= 1000 ; i++ ) {
            if ( prime(i) ) {
                a[i] = a[i - 1] + i ;
            }else {
                a[i] = a[i - 1] ;
            }
        }

        int r = rev(n) ;
        int ans = 0 ;
        
        return a[max(n , r)] - a[min(n , r) - 1] ;
    }
};
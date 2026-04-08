class Solution {
public:
    string getSmallestString(int n, int k) {
        string s = "" ;
        s.append(n , 'a') ;

        if ( k == n ) return s ;

        k -= n ;

        for ( int i = n - 1 ; i >= 0 && k > 0 ; i-- ) {
            k++ ;
            int curr = min ( k , 26 ) ;
            
            s[i] = 'a' + (curr - 1) ;
            k -= curr ;
        }

        return s ;
    }
};
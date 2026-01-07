class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num) ;
        int n = s.size() ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            int maxx = s[i] - '0' ;
            int idx = -1 ;

            for ( int j = n - 1 ; j >= i ; j-- ){
                if ( maxx < (s[j] - '0') ) {
                    idx = j ;
                    maxx = s[j] - '0' ;
                }
            }

            if ( idx != -1 ) {
                swap(s[i] , s[idx]) ;
                return stoi(s) ;
            }
        }
        return num ;
    }
};
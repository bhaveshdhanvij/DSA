class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0 ;
        for ( int x = num1 ; x <= num2 ; x++ ) {
            string s = to_string(x) ;
            int n = s.size() ;
            if ( n < 3 ) continue ;
            for ( int i = 1 ; i < n - 1 ; i++ ) {
                int a = s[i - 1] - '0' ;
                int b = s[i] - '0' ;
                int c = s[i + 1] - '0' ;
                if ( (b > a && b > c) || (b < a && b < c) ) ans++ ;
            }
        }
        return ans ;
    }
};
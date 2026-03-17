class Solution {
public:
    int numSub(string s) {
        // TC : O(N) , SC : O(1) 
        const int mod = 1000000007 ;
        int n = s.length() ;
        long c = 0 , ans = 0 ;

        for ( char ch : s ) {
            if ( ch == '1' ) c++ ; 
            else {
                long add = (c * (c + 1)) / 2 ;
                add = add % mod ;
                ans = (ans + add) % mod ; 
                c = 0 ;
            }
        }
        long add = (c * (c + 1)) / 2 ;
        add = add % mod ;
        ans = (ans + add) % mod ;

        return (int)ans ;
    }
};
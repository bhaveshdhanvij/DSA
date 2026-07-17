class Solution {
public:
    string countAndSay(int n) {
        string ans = "1" ;
        for ( int i = 2 ; i <= n ; i++ ) {
            string t = "" ;
            int c = 1 ;
            for ( int j = 1 ; j < ans.size() ; j++ ) {
                if ( ans[j] == ans[j - 1] ) c++ ;
                else {
                    t += to_string(c) ;
                    t += ans[j - 1] ;
                    c = 1 ;
                }
            }
            t += to_string(c) ;
            t += ans.back() ;

            ans = t ; 
        }
        return ans ;
    }
};
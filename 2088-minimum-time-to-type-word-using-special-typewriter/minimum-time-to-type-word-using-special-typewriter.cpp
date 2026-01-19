class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.length() ;

        char curr = 'a' ;

        for ( char c : word ) {
            int d = abs(c - curr) ;
            
            ans += min ( d , 26 - d ) ;

            curr = c ;
        }

        return ans ;
    }
};
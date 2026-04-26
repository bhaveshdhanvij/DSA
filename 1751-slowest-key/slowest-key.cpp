class Solution {
public:
    char slowestKey(vector<int>& a, string s) {
        char ans ;
        int maxx = -1 , curr = 0 ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( i == 0 ) curr = a[i] ;
            else curr = a[i] - a[i - 1] ;
            
            if ( curr > maxx ) {
                ans = s[i] ;
                maxx = curr ;
            }else if ( curr == maxx ) {
                ans = max ( ans , s[i] ) ;
            }
        }

        return ans ;
    }
};
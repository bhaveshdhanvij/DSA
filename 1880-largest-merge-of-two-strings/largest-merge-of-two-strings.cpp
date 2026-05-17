class Solution {
public:
    string largestMerge(string a, string b) {
        int n = a.size() , m = b.size() ;
        string ans = "" ;
        int i = 0 , j = 0 ;
        while ( i < n && j < m ) {
            if ( a.substr(i) > b.substr(j) ) {
                ans += a[i++] ;
            }else {
                ans += b[j++] ;
            }
        }
        while ( i < n ) ans += a[i++] ;
        while ( j < m ) ans += b[j++] ;

        return ans ; 
    }
};
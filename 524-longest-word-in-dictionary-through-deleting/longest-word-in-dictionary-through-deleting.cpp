class Solution {
public:
    bool helper( string s , string a ) {
        int n = s.size() , m = a.size() ;
        int i = 0 , j = 0 ;
        while ( i < n && j < m ) {
            if ( s[i] != a[j] ) {
                i++ ;
            }else {
                i++ , j++ ;
            }
        }
        return j == m ;
    }
    string findLongestWord(string s, vector<string>& d) {
        int maxx = 0 ;
        string ans = "" ;
        for ( string a : d ) {
            if ( helper(s , a) ) {
                int curr = a.size() ;
                if ( curr > maxx ) {
                    ans = a ;
                    maxx = curr ;
                }else if ( curr == maxx ) {
                    ans = min ( ans , a ) ;
                }
            }
        }
        return ans ;
    }
};
class Solution {
public:
    bool isVowel( char c ) {
        if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return true ;
        return false ;
    }
    bool helper(string s) {
        int n = s.size() ;
        return isVowel(s[0]) && isVowel(s[n -1]) ;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size() ;
        vector<int> p(n , 0) ;
        int count = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( helper(words[i]) ) count++ ;
            p[i] = count ;
        } 
        int m = queries.size() ;
        vector<int> ans(m , 0) ;
        for ( int i = 0 ; i < m ; i++ ) {
            int l = queries[i][0] ;
            int r = queries[i][1] ;
            if ( l == 0 ) {
                ans[i] = p[r] ;
            }else {
                ans[i] = p[r] - p[l - 1] ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int countVowelSubstrings(string s) {
        unordered_set<char> set = { 'a' , 'e' , 'i' , 'o' , 'u' } ;
        int n = s.size() ;

        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            unordered_set<char> a ;
            string t = "" ;
            for ( int j = i ; j < n ; j++ ) {
                t += s[j] ;
                a.insert(s[j]) ;
                if ( a == set ) ans++ ;
                if ( a.size() >= 5 && a != set ) break ;
            }
        }

        return ans ;
    }
};
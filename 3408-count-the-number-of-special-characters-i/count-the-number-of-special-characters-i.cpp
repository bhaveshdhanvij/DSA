class Solution {
public:
    int numberOfSpecialChars(string s) {
        unordered_set<char> uset ;
        for ( char c : s ) uset.insert(c) ;
        int ans = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( uset.count(i + 'a') && uset.count(i + 'A') ) {
                ans++ ;
            }
        } 
        return ans ;
    }
};
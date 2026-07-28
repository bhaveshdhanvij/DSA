class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> mp(26 , 0) ;
        for ( char c : s ) mp[c - 'a']++ ;
        string l = "" , m = "" ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            l += string(mp[i] / 2 , char('a' + i)) ;
            if ( mp[i] & 1 ) m = char('a' + i) ; 
        }
        string r = l ;
        reverse(r.begin() , r.end()) ;
        return l + m + r ;
    }
};
class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) ;
        string a = to_string(n * 2) ;
        string b = to_string(n * 3) ;

        unordered_map<char,int> mp ;
        for ( char c : s ) {
            if ( c == '0' || mp.count(c) ) return false ;
            mp[c]++ ;
        }
        for ( char c : a ) {
            if ( c == '0' || mp.count(c) ) return false ;
            mp[c]++ ;
        }
        for ( char c : b ) {
            if ( c == '0' || mp.count(c) ) return false ;
            mp[c]++ ;
        }

        return mp.size() == 9 ;
    }
};
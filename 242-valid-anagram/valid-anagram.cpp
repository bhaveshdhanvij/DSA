class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort ( s.begin() , s.end() ) ;
        // sort ( t.begin() , t.end() ) ;
        // return s == t ;


        map<char,int> a , b ;
        for ( char c : s ) a[c]++ ;
        for ( char c : t ) b[c]++ ;
        return a == b ;
    }
};
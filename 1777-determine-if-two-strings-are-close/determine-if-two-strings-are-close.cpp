class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if ( word1.size() != word2.size() ) return false ;
        unordered_map<char,int> a , b ;
        
        for ( char c : word1 ) a[c]++ ;
        for ( char c : word2 ) b[c]++ ;

        for ( auto &p : a ) {
            if ( !b.count(p.first) ) return false ;
        }
        vector<int> t , s ;
        for ( auto p : a ) t.push_back(p.second) ;
        for ( auto p : b ) s.push_back(p.second) ;

        sort ( t.begin() , t.end() ) ;
        sort ( s.begin() , s.end() ) ;
        
        return s == t ;
    }
};
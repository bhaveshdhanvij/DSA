class Solution {
public:
    bool helper(string s , string t) {
        int n = s.size() , m = t.size() ;
        if ( n != m ) return false ;
        int count = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] != t[i] ) count++ ;
        }
        return count <= 2 ;
    }
    vector<string> twoEditWords(vector<string>& a, vector<string>& d) {
        vector<string> ans ;
        for ( string s : a ) {
            for ( string t : d ) {
                if ( helper(s , t) ) {
                    ans.push_back(s) ;
                    break ;
                }
            }
        }
        return ans ;
    }
};
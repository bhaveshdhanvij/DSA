class Solution {
public: 
    bool helper( string s ) {
        int idx = -1 ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( isdigit(s[i]) ) return false ;
            else if ( s[i] == '-' ) {
                if ( idx != -1 ) return false ;
                idx = i ;
            }else if ( s[i] == '!' || s[i] == '.' || s[i] == ',' ) {
                if ( i != s.size() - 1 ) return false ;
            }
        }
        if ( idx != -1 ) {
            if ( !( idx - 1 >= 0 && s[idx - 1] >= 'a' && s[idx - 1] <= 'z' && idx + 1 < s.size() && s[idx + 1] >= 'a' && s[idx + 1] <= 'z') ) {
                return false ;
            }
        } 

        return true ;
    }
    int countValidWords(string s) {
        stringstream ss(s) ;
        string word ;
        int ans = 0 ;
        while ( ss >> word ) {
            if ( helper(word) ) {
                ans++ ;
            }
        }
        return ans ;
    }
};
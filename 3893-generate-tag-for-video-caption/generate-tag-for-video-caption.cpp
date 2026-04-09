class Solution {
public:
    string helper( string s ) {
        if ( s.empty() ) return s ;

       for ( char &c : s ) {
            c = tolower(c) ; 
       }
       s[0] = toupper(s[0]) ;
       return s ;
    }
    string generateTag(string s) {
        stringstream ss(s) ;
        string word ;
        int count = 0 ;
        string ans = "#" ;

        while ( ss >> word ) {
            count++ ;
            
            for ( char &c : word ) c = tolower(c) ;

            if ( count == 1 ) {
                ans += word ;
            }else {
                ans += helper(word) ;
            }

            if ( ans.size() > 100 ) break ;
        }
        if ( ans.size() > 100 ) ans = ans.substr(0 , 100) ;
        return ans ;
    }
};
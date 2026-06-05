class Solution {
public:
    string maskPII(string s) {
        int pos ;
        if ( s.find('@') != string::npos ) {
            // email address  

            pos = s.find('@') ;
            
            string name = s.substr(0 , pos) ;
            string d = s.substr(pos + 1) ;

            for ( char &c : name ) c = tolower(c) ;
            for ( char &c : d ) c = tolower(c) ;

            name = string(1 , name[0]) + "*****" + string(1 , name[name.size() - 1]) ;
            return name + "@" + d ;
        }else {
            // phone number

            string temp = "" ;
            for ( char c : s ) {
                if ( isdigit(c) ) {
                    temp += c ;
                }
            }

            int cc = temp.size() - 10 ;
            string ans = "" ;
            for ( int i = temp.size() - 1 ; i >= 0 && ans.size() < 4 ; i-- ) {
                ans += temp[i] ;
            }
            reverse(ans.begin() , ans.end()) ;

            if ( cc == 0 ) return "***-***-" + ans ;
            if ( cc == 1 ) return "+*-***-***-" + ans ;
            if ( cc == 2 ) return "+**-***-***-" + ans ;
            if ( cc == 3 ) return "+***-***-***-" + ans ;
        }

        return "!" ;
    }
};
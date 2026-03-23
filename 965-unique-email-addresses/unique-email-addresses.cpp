class Solution {
public:
    string helper(string s) {
        int n = s.size() ;
        string b = "" ;
        for ( char c : s ) {
            if ( c == '+' ) return b ;
            else if ( c != '.' ) b += c ;
        }
        return b ;
    }
    int numUniqueEmails(vector<string>& a) {
        unordered_set<string> s ;
        int n = a.size() ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            auto idx = a[i].find("@") ;
            string l = a[i].substr(0 , idx) ;
            string d = a[i].substr(idx) ;
            
            l = helper(l) ;
            string temp = l + d ;
            s.insert(temp) ;
        }

        return (int)s.size() ;
    }
};
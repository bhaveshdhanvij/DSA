class Solution {
public:
    bool match ( string a , string b ) {
        int n = a.size() ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            if ( a[i + 1] - a[i] != b[i + 1] - b[i] ) {
                return false ;
            }
        }
        return true ;
    }
    string oddString(vector<string>& a) {
        int count = 0 ;
        int idx = -1 ;

        for ( int i = 1 ; i < a.size() ; i++ ) {
            if ( match(a[0] , a[i]) ) count++ ;
            else idx = i ;
        }

        if ( count == 0 ) return a[0] ; // the first string is only the odd one 
        return a[idx] ;
    }
};
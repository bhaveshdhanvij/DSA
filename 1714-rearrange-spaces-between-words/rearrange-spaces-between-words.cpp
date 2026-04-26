class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> a ;
        string ans = "" ;
        stringstream ss(text) ;
        string word ;
        
        int w = 0 , sp = 0 ;
        for ( char c : text ) {
            if ( c == ' ' ) sp++ ;
        }

        while ( ss >> word ) {
            w++ ;
            a.push_back(word) ;
        }

        if ( w == 1 ) {
            ans += a[0] ;
            for ( int i = 0 ; i < sp ; i++ ) ans += ' ' ;
            return ans ;
        }

        int each = sp / (w - 1) ;
        int ex = sp % (w - 1) ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            if ( !ans.empty() ) {
                for ( int i = 0 ; i < each ; i++ ) ans += ' ' ; 
            }
            ans += a[i] ;
        }

        for ( int i = 0 ; i < ex ; i++ ) ans += ' ' ;
        return ans ;
    }
};
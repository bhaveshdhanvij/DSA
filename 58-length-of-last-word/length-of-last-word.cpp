class Solution {
public:
    int lengthOfLastWord(string s) {
        // int ans = 0 ;
        // int n = s.size() ;
        // string w = "" ;
        // for ( int i = 0 ; i < n ; ) {
        //     while ( i < n && s[i] == ' ' ) i++ ;
        //     while ( i < n && s[i] != ' ' ) {
        //         w += s[i] ;
        //         i++ ;
        //     }
        //     if ( !w.empty() ) ans = w.length() ;
        //     w.clear() ;
        // }
        // return ans ;


        stringstream ss(s) ;
        string word , ans ;
        while ( ss >> word ) {
            ans = word ;
        }
        return ans.length() ;
    }
};
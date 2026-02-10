class Solution {
public:
    string arrangeWords(string text) {
        stringstream ss(text) ;
        string word ;
        
        vector<string> a ;
        while ( ss >> word ) {
            string t ;
            for ( char c : word ) {
                t += tolower(c) ;
            }
            a.push_back(t) ; 
        }

        stable_sort ( a.begin() , a.end() , [](const string& x ,const string& y) {
            return x.length() < y.length() ;
        });

        string ans ;
        for ( string s : a ) {
            if ( !ans.empty() ) {
                ans += ' ' ; 
            }
            ans += s ;
        }

        ans[0] = toupper(ans[0]) ;

        return ans ;
    }
};
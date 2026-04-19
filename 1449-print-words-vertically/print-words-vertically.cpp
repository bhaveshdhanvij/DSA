class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s) ;
        string word ;

        vector<string> a ;
        int w = 0 ;
        while ( ss >> word ) {
            a.push_back(word) ;
            w = max ( w , (int)word.size() ) ;
        }
        
        vector<string> ans ;
        for ( int j = 0 ; j < w ; j++ ) {
            string temp = "" ;

            for ( int i = 0 ; i < a.size() ; i++ ) {
                if ( a[i].size() < j + 1 ) temp += " " ;
                else temp += a[i][j] ;
            }

            while ( temp.size() > 0 && temp.back() == ' ' ) {
                temp.pop_back() ;
            }
            ans.push_back(temp) ;
        }

        return ans ;
    }
};
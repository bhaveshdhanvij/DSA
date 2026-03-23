class Solution {
public:
    vector<string> stringMatching(vector<string>& a) {
        sort ( a.begin() , a.end() , [&](const string& x , const string& y) {
            if ( x.length() == y.length() ) return x < y ;
            return x.length() < y.length() ;
        }) ;
        
        int n = a.size() ;
        vector<string> ans ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                if ( a[j].find(a[i]) != string::npos ) {
                    ans.push_back(a[i]) ;
                    break ;
                }
            }
        }
        return ans ;
    }
};
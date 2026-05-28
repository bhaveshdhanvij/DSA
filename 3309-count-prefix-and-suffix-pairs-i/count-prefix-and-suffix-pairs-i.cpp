class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& v) {
        // sort ( v.begin() , v.end() , [&](const string& a , const string& b) {
        //     return a.length() < b.length() ;
        // });

        int ans = 0 ;

        int n = v.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            string s = v[i] ;
            for ( int j = i + 1 ; j < n ; j++ ) {
                string t = v[j] ;
                if ( t.starts_with(s) && t.ends_with(s) ) {
                    ans++ ;
                }
            }
        }

        return ans ;
    }
};
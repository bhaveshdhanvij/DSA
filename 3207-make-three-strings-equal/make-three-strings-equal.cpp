class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        vector<string> s = {s1 , s2 , s3} ;
        sort ( s.begin() , s.end() ) ;
        int i = 0 ;
        while ( i < s[0].size() && i < s[2].size() && s[0][i] == s[2][i] ) i++ ;
        if ( i == 0 ) return -1 ;
        return s[0].size() + s[1].size() + s[2].size() - 3 * i ;
    }
};
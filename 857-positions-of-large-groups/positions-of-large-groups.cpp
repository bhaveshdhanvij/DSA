class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans ;
        int n = s.size() ;

        for ( int i = 0 ; i < n ; ) {
            char st = s[i] ;
            int count = 0 ;
            int temp = i ;

            while ( i < n && s[i] == st ) {
                i++ ;
                count++ ;
            }

            if ( count >= 3 ) {
                ans.push_back({temp , i - 1}) ;
            }
        }

        return ans ;
    }
};
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int r = startPos[0] , c = startPos[1] ;
        vector<int> ans ;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            int nr = r , nc = c ;

            int curr = 0 ;
            for ( int j = i ; j < s.size() ; j++ ) {
                if ( s[j] == 'L' ) nc-- ;
                else if ( s[j] == 'R' ) nc++ ;
                else if ( s[j] == 'U' ) nr-- ;
                else nr++ ;

                if ( !(nr >= 0 && nr < n && nc >= 0 && nc < n) ) break ;
                curr++ ;
            }

            ans.push_back(curr) ;
        }

        return ans ;
    }
};
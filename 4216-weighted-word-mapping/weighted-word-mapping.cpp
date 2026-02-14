class Solution {
public:
    string mapWordWeights(vector<string>& a, vector<int>& b) {
        string ans = "" ;
        for ( int i = 0 ; i < a.size() ; i++ ) {
            string s = a[i] ;
            int curr = 0 ;
            for ( char c : s ) {
                int idx = c - 'a' ;
                curr += b[idx] ;
            }
            curr = curr % 26 ;
            ans += 'z' - curr ;
        }

        return ans ;
    }
};
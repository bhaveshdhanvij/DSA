class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        int ans = 0 ;
        unordered_set<string> uset ;
        for ( int x : a ) {
            string s = to_string(x) ;
            int size = s.size() ;
            for ( int i = 1 ; i <= size ; i++ ) {
                uset.insert(s.substr(0 , i)) ;
            }
        }
        for ( int x : b ) {
            string s = to_string(x) ;
            int size = s.size() ;
            for ( int i = 1 ; i <= size ; i++ ) {
                string t = s.substr(0 , i) ;
                if ( uset.count(t) ) {
                    ans = max ( ans , i ) ;
                }
            }
        }

        return ans ;
    }
};
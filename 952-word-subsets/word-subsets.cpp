class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        unordered_map<char,int> mp ;
        for ( string s : b ) {
            unordered_map<char,int> temp ;
            for ( char c : s ) temp[c]++ ;

            for ( auto p : temp ) {
                mp[p.first] = max ( mp[p.first] , p.second ) ;
            }
        }

        vector<string> ans ;
        for ( string s : a ) {
            unordered_map<char,int> t ;
            for ( char c : s ) t[c]++ ;

            bool f = true ;
            for ( auto p : mp ) {
                if ( t[p.first] < p.second ) {
                    f = false ;
                    break ;
                }
            }

            if ( f ) ans.push_back(s) ;
        }

        return ans ;
    }
};
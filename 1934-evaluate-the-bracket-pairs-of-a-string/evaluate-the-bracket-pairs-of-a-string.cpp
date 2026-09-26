class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string> mp ;
        for ( auto p : k ) {
            mp[p[0]] = p[1] ;
        }
        string ans = "" ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == '(' ) {
                string t = "" ;
                int j = i + 1 ;
                while ( s[j] != ')' ) {
                    t += s[j] ;
                    j++ ;
                }
                if ( mp.count(t) ) ans += mp[t] ;
                else ans += '?' ;
                i = j ;
            }else {
                ans += s[i] ;
            }
        } 
        return ans ;
    }
};
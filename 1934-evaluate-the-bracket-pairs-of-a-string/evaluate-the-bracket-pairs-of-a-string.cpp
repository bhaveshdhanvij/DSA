class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string> mp ;
        for ( auto x : k ) mp[x[0]] = x[1] ;

        int i = 0 , n = s.size() ;
        string ans = "" ;

        while ( i < n ) {
            if ( s[i] == '(' ) {
                i++ ;
                string t = "" ;
                while ( i < n && s[i] != ')' ) {
                    t += s[i] ;
                    i++ ;
                }
                if (mp.count(t)) {
                    ans += mp[t] ;
                }else {
                    ans += '?' ;
                }
            }else {
                ans += s[i] ;
            }
            i++ ;
        } 

        return ans ;
    }
};
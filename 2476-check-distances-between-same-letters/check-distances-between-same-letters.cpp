class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        unordered_map<char,int> mp ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( !mp.count(s[i]) ) mp[s[i]] = i ;
            else {
                mp[s[i]] = i - mp[s[i]] - 1 ;
            }
        }

        for ( int i = 0 ; i < 26 ; i++ ) {
            char c = i + 'a' ;
            if ( !mp.count(c) ) continue ;

            if ( mp[c] != d[i] ) return false ;
        }

        return true ;
    }
};
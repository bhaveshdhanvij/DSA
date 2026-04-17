class Solution {
public:
    string helper( int n ) {
        string s = to_string(n) ;
        reverse( s.begin() , s.end() ) ;
        int idx = 0 ;
        while ( idx < s.size() && s[idx] == '0' ) idx++ ;
        if ( idx == s.size() ) return "0" ;
        return s.substr(idx) ;
    }
    int minMirrorPairDistance(vector<int>& a) {
        unordered_map<string,int> mp ;
        int ans = INT_MAX ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            string s = to_string(a[i]) ;

            if ( mp.count(s) ) {
                ans = min ( ans , i - mp[s] ) ;
            }

            string t = helper(a[i]) ;
            mp[t] = i ;
        }
        
        return ans == INT_MAX ? -1 : ans ;
    }
};
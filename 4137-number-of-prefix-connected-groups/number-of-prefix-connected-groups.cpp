class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp ;

        for ( string &s : words ) {
            if ( s.size() >= k ) {
                string p = s.substr(0 , k) ;
                mp[p]++ ;
            }
        }

        int ans = 0 ;
        for ( auto &p : mp ) {
            if ( p.second >= 2 ) ans++ ;
        }

        return ans ;

    }
};
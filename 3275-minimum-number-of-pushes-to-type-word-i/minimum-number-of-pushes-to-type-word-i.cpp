class Solution {
public:
    int minimumPushes(string s) {
        vector<int> mp(26 , 0) ;
        for ( char c : s ) mp[c - 'a']++ ;
        sort(mp.rbegin() , mp.rend()) ;
        int ans = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( mp[i] == 0 ) break;
            ans += mp[i] * (i / 8 + 1) ;
        }
        return ans ;
    }
};
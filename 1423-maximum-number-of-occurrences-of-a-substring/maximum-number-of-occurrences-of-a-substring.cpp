class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> mp ;
        int ans = 0 ;

        int n = s.size() ;
        int l = 0 , d = 0 ;

        vector<int> f(26 , 0) ;
        
        for ( int r = 0 ; r < n ; r++ ) {
            ++f[s[r] - 'a'] ;
            if ( f[s[r] - 'a'] == 1 ) d++ ;

            if ( r - l + 1 > minSize ) {
                --f[s[l] - 'a'] ;
                if ( f[s[l] - 'a'] == 0 ) d-- ;
                l++ ;
            }

            if ( r - l + 1 == minSize && d <= maxLetters ) {
                string t = s.substr(l , minSize) ;
                mp[t]++ ;
                ans = max ( ans , mp[t] ) ;
            }
        }  
        return ans ;
    }
};
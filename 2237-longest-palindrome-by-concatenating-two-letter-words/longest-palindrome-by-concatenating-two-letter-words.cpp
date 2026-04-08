class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        unordered_map<string,int> mp ;
        for ( string s : a ) mp[s]++ ;

        bool flag = false ;
        int ans = 0 ;

        for ( auto &it : mp ) {
            string s = it.first ;
            string t = s ;
            reverse(t.begin() , t.end()) ;

            if ( s == t ) {
                ans += ( it.second / 2 ) * 4 ;
                if ( it.second % 2 ) {
                    flag = true ;
                } 
            }else if ( s < t && mp.count(t) ) {
                ans += min ( it.second , mp[t] ) * 4 ; 
            }
        }

        if ( flag ) ans += 2 ;
        return ans ;
    }
};
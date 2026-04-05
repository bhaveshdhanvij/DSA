class Solution {
public:
    char helper(char c) {
        if ( c >= '0' && c <= '9' ) {
            return '0' + ('9' - c) ;
        }
        return 'a' + ('z' - c) ;
    }
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp ;
        for ( char c : s ) mp[c]++ ;
        
        int ans = 0 ;
        unordered_set<char> seen ;

        for ( char c : s ) {
            if ( seen.count(c) ) continue ;

            int t1 = mp[c] ;
            
            char m = helper(c) ;

            int t2 = mp.count(m) ? mp[m] : 0 ;

            ans += abs(t1 - t2) ;

            seen.insert(c) ;
            seen.insert(m) ;
        }

        return ans ;
    }
};
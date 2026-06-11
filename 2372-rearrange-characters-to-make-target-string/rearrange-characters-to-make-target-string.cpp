class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp , t ;
        
        for ( char c : s ) mp[c]++ ;
        for ( char c : target ) t[c]++ ;

        int ans = INT_MAX  ;
        for ( auto p : t ) {
            int num = mp.count(p.first) ? mp[p.first] : 0 ;
            int den = p.second ;

            ans = min ( ans , num / den ) ;
        }   

        return ans ;
    }
};
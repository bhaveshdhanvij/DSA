class Solution {
public:
    int canBeTypedWords(string s, string b) {
        unordered_map<char,int> mp ;
        for ( char c : b ) {
            mp[c]++ ;
        }
        int ans = 0 ;
        stringstream ss(s) ;
        string word ;
        while ( ss >> word ) {
            bool flag = true ;
            for ( char c : word ) {
                if ( mp.count(c) ) {
                    flag = false ;
                    break ;
                }
            }
            if ( flag ) ans++ ;
        }

        return ans ;
    }
};
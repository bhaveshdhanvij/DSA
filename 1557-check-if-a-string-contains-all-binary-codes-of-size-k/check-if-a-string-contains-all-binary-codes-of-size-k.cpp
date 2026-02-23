class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> mp ;
        
        int n = s.size() ;
        int r = pow(2 , k) ;

        for ( int i = 0 ; i <= n - k ; i++ ) {
            string t = s.substr(i , k) ;
            mp[t]++ ;
        }

        return mp.size() == r ;
    }
};
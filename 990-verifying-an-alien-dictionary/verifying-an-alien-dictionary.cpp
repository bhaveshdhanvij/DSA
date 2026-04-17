class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int c = 0 ;
        unordered_map<char,int> mp ;
        for ( char ch : order ) {
            mp[ch] = ++c ;
        }

        vector<string> a = words ;
        sort ( a.begin() , a.end() , [&](const string x , const string y) {
            int n = x.size() , m = y.size() ;
            for ( int i = 0 ; i < min ( n , m ) ; i++ ) {
                if ( x[i] == y[i] ) continue ;
                return mp[x[i]] < mp[y[i]] ;
            }
            return n < m ;
        });

        return a == words ;
    }
};
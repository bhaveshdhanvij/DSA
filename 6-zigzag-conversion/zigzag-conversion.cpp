class Solution {
public:
    string convert(string s, int n) {
        if ( n == 1 || n >= s.size() ) return s ;
        vector<string> rows(n) ;
        bool flag = false ;
        int curr = 0 ;
        for ( char c : s ) {
            rows[curr] += c ;
            if ( curr == 0 || curr == n - 1 ) flag = !flag ;
            if ( flag ) curr++ ;
            else curr-- ;
        }
        string ans ;
        for ( auto p : rows ) ans += p ;
        return ans ;
    }
};
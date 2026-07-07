class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n) ;
        string ans = "" ;
        int sum = 0 ;
        for ( char c : s ) {
            if ( c != '0') ans += c ;
            sum += c - '0' ;
        }
        if (ans.empty()) return 0LL ;
        long long t = stoll(ans) ;
        return t * sum ;
    }
};
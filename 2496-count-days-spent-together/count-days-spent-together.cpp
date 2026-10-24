class Solution {
public:
    int countDaysTogether(string a, string b, string c, string d) {
        vector<int> m = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ;
        auto f = [&](string s) {
            int x = stoi(s.substr(0 , 2)) ;
            int y = stoi(s.substr(3, 2)) ;
            for ( int i = 0 ; i < x - 1 ; i++ ) y += m[i] ;
            return y ;
        };
        int x = max(f(a) , f(c)) ;
        int y = min(f(b) , f(d)) ;
        return max(0 , y - x + 1) ;
    }
};
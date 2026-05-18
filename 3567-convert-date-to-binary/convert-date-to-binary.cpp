class Solution {
public:
    string helper( string s ) {
        int n = stoi(s) ;
        string ans = "" ;
        while (n) {
            int r = n % 2 ;
            ans = to_string(r) + ans ;
            n /= 2 ;
        }
        return ans ;
    }
    string convertDateToBinary(string s) {
        string y = s.substr(0 , 4) ;
        string m = s.substr(5 , 2) ;
        string d = s.substr(8 , 2) ;

        return helper(y) + "-" + helper(m) + "-" + helper(d) ;
    }
};
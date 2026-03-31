class Solution {
public:
    pair<int,int> parse(string s) {
        int plus = s.find('+') ;
        int real = stoi(s.substr(0 , plus)) ;
        int imag = stoi(s.substr(plus + 1 , s.size() - plus - 2)) ;
        return {real , imag} ;
    }
    string complexNumberMultiply(string s, string t) {
        auto [a , b] = parse(s) ;
        auto [c , d] = parse(t) ;
        int real = a * c - b * d ;
        int imag = a * d + b * c ;

        return to_string(real) + '+' + to_string(imag) + 'i' ;
    }
};
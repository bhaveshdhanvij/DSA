class Solution {
public:
    bool canBeEqual(string a, string b) {
        string a1 = string() + a[0] + a[2] ;
        string a2 = string() + a[1] + a[3] ;
        string b1 = string() + b[0] + b[2] ;
        string b2 = string() + b[1] + b[3] ;

        sort ( a1.begin() , a1.end() ) ;
        sort ( a2.begin() , a2.end() ) ;
        sort ( b1.begin() , b1.end() ) ;
        sort ( b2.begin() , b2.end() ) ;

        return a1 == b1 && a2 == b2 ; 
    }
};
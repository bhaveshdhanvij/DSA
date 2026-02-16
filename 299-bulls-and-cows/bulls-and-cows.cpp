class Solution {
public:
    string getHint(string s, string g) {
        int x = 0 , y = 0 ;
        unordered_map<char,int> a , b ;
        
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == g[i] ) x++ ;
            else {
                a[s[i]]++ ;
                b[g[i]]++ ;
            }
        }

        for ( auto &p : b ) {
            if ( a.count(p.first) ) {
                y += min ( p.second , a[p.first] ) ;
            }
        }

        string ans = to_string(x) + "A" + to_string(y) + "B" ;

        return ans ;
    }
};
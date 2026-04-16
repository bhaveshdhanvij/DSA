class Solution {
public:
    bool reportSpam(vector<string>& a, vector<string>& b) {
        unordered_set<string> s(b.begin() , b.end()) ;
        int count = 0 ;

        for ( string t : a ) {
            if ( s.count(t) ) count++ ;
        }

        return count >= 2 ;
    }
};
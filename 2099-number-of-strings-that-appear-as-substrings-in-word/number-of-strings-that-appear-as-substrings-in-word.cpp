class Solution {
public:
    int numOfStrings(vector<string>& a, string s) {
        int ans = 0 ;
        for ( string t : a ) {
            if ( s.find(t) != string::npos ) ans++ ;
        }
        return ans ;
    }
};
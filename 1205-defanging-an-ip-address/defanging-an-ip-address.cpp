class Solution {
public:
    string defangIPaddr(string s) {
        // TC : O(N) , SC : O(N) 
        string ans ;
        for ( char c : s ) {
            if ( c == '.' ) ans += "[.]" ;
            else ans += c ;
        }
        return ans ;
    }
};
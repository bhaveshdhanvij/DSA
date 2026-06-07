class Solution {
public:
    vector<string> ans ;
    void helper( string s , int n , int k , int curr ) {
        if ( curr > k ) return ;

        if ( s.size() == n ) {
            ans.push_back(s) ;
            return ;
        }

        int idx = s.size() ;
        
        helper(s + '0' , n , k , curr) ;

        if ( s.empty() || s.back() == '0' ) {
            helper(s + '1' , n , k , curr + idx) ;
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string s = "" ;
        helper(s , n , k , 0) ;
        return ans ;
    }
};
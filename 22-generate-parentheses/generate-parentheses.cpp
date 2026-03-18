class Solution {
public:
    void helper(vector<string>& ans , int a , int b , string s , int n ) {
        if ( a == n && b == n ) {
            ans.push_back(s) ;
            return ;
        }

        if ( a > b ) {
            helper( ans , a , b + 1 , s + ")" , n ) ;
        }

        if ( a < n ) {
            helper( ans , a + 1 , b , s + "(" , n ) ;
        } 
    }
    vector<string> generateParenthesis(int n) {
        // TC : O(2**N) , SC : O(N)
        vector<string> ans ;
        helper( ans , 0 , 0 , "" , n) ;
        return ans ;
    }
};
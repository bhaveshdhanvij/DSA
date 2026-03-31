class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> path ;
        f(0 , s , path , ans) ;
        return ans ;
    }

    void f(int index , string &s , vector<string> &path , vector<vector<string>> &ans ) {
        if ( index == s.length() ) {
            ans.push_back(path) ;
            return ;
        }

        for ( int i = index ; i < s.size() ; i++ ) {
            if ( isPalindrome(s , index , i) ) {
                path.push_back(s.substr(index , i - index + 1)) ;
                f(i + 1 , s , path , ans) ;
                path.pop_back() ;
            }
        }
    }

    bool isPalindrome(string &s , int st , int end ) {
        while ( st < end ) {
            if ( s[st++] != s[end--] ) {
                return false ;
            }
        }
        return true ;
    }
};
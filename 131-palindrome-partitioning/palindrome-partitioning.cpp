class Solution {
public:
    // Meta
    // Microsoft
    // Amazon
    // Adobe
    // Infosys
    vector<vector<string>> ans ;
    vector<vector<bool>> dp ;

    // bool ispalindrome( string& s , int l , int r ) {
    //     while ( l < r ) {
    //         if ( s[l] != s[r] ) return false ;
    //         l++ , r-- ;
    //     }
    //     return true ;
    // }
    void dfs(string& s , int st , vector<string>& path) {
        if ( st == s.size() ) {
            ans.push_back(path) ;
            return ;
        }

        for ( int end = st ; end < s.size() ; end++ ) {
            if ( dp[st][end] ) {
                path.push_back(s.substr(st , end - st + 1)) ;
                dfs(s , end + 1 , path) ;
                path.pop_back() ;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // Optimized recursion 
        
        int n = s.size() ;
        dp.assign(n , vector<bool>(n , false)) ;

        for ( int i = n - 1 ; i >= 0 ; i-- ) {
            for ( int j = i ; j < n ; j++ ) {
                if ( s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true ;
                }
            }
        }
        vector<string> path ;
        dfs(s , 0, path) ;
        return ans ;
    }
};
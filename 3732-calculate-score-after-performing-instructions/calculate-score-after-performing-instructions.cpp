class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size() ;
        vector<bool> vis(n , false) ;

        int i = 0 ;
        long long ans = 0 ;
        while ( i >= 0 && i < n && !vis[i] ) {
            vis[i] = true ;
            if ( instructions[i] == "add" ) {
                ans += values[i] ;
                i++ ;
            }else {
                i += values[i] ;
            }
        }

        return ans ;
    }
};
class Solution {
public:
    // Amazon
    // Meta
    // Sprinklr
    // Google
    void dfs(int i , vector<vector<int>>& a , vector<bool> &vis) {
        vis[i] = true ;
        for ( int j = 0 ; j < a[i].size() ; j++ ) {
            if ( a[i][j] == 1 && !vis[j] ) {
                dfs(j , a , vis) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        // Optimal Approach : Using standard DFS 
        // TC : O(N * N) , SC : O(N) 

        int n = a.size() ;
        vector<bool> vis(n , false) ;
        
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( !vis[i] ) {
                ans++ ;
                dfs(i , a , vis) ;
            }
        }
        
        return ans ;
    }
};
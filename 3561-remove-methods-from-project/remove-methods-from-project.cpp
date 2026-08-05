class Solution {
public:
    void helper(int u , vector<vector<int>> &adj , vector<bool>& sus) {
        sus[u] = true ;
        for ( int v : adj[u] ) {
            if ( sus[v] == false ) {
                helper(v , adj , sus) ;
            }
        } 
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& a) {
        vector<vector<int>> adj(n) ;
        for ( auto e : a ) {
            adj[e[0]].push_back(e[1]) ;
        }
        vector<bool> sus(n , false) ;
        helper(k , adj , sus) ;
        for ( auto e : a ) {
            int u = e[0] ;
            int v = e[1] ;
            if ( sus[u] == false && sus[v] == true ) {
                vector<int> ans ;
                for ( int i = 0 ; i < n ; i++ ) ans.push_back(i) ;
                return ans ;
            }
        }
        vector<int> ans ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( sus[i] == false ) ans.push_back(i) ;
        }

        return ans ;
    }
};
class Solution {
public:
    const int mod = 1000000007 ;
    long long modpow(long long a , long long b ) {
        long long ans = 1 ;
        while ( b ) {
            if ( b & 1 ) {
                ans = ans * a % mod ;
            }

            a = a * a % mod ; // square the a 
            b >>= 1 ; // divide the pow by 2
        }
        return ans ;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1 ;
        
        vector<vector<int>> g(n + 1) ;
        for ( auto &e : edges ) {
            int u = e[0] ;
            int v = e[1] ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }
        
        queue<int> q ;
        q.push(1) ;

        vector<int> vis(n + 1 , 0) ;
        vis[1] = 1 ;

        int d = -1 ;
        while(!q.empty()) {
            int size = q.size() ;
            d++ ;

            while(size--) {
                int u = q.front() ;
                q.pop() ;

                for ( int v : g[u] ) {
                    if (!vis[v] ) {
                        q.push(v) ;
                        vis[v] = 1 ;
                    }
                }
            }
        }
        return (int)modpow(2 , d - 1) ;
    }
};
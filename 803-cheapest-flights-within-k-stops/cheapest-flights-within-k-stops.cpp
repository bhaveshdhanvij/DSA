class Solution {
public:
    // Apple
    // Stripe
    // Amazon
    // Airbnb
    // Oracle
    // DE Shaw
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>> g[n] ; // u => (v , wt)

        for ( int i = 0 ; i < f.size() ; i++ ) {
            int u = f[i][0] ;
            int v = f[i][1] ;
            int wt = f[i][2] ;
            g[u].push_back({v , wt}) ;
        }

        queue<pair<int,pair<int,int>>> q ; // node => (cost , stops) 
        vector<int> d(n , INT_MAX) ;

        d[src] = 0 ;
        q.push({src , {0 , 0}}) ;

        while (q.size() > 0) {
            auto curr = q.front() ;
            q.pop() ;

            int u = curr.first ;
            int cost = curr.second.first ;
            int stops = curr.second.second ;

            if ( stops > k ) continue ;


            for ( auto e : g[u] ) {
                int v = e.first ;
                int wt = e.second ;


                if ( cost + wt < d[v] ) {
                    d[v] = cost + wt ;
                    q.push({v , {cost + wt , stops + 1}}) ;
                }
            }
        }

        return d[dst] == INT_MAX ? -1 : d[dst] ;
    }
};
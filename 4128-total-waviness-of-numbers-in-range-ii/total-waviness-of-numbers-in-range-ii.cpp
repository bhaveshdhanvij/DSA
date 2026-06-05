class Solution {
public:
    using ll = long long ;
    struct Node {
        ll cnt , wav ;
    };
    string s ; 
    map<tuple<int,int,int,int,int>,Node> memo ;
    Node dfs(int pos , int tight , int started , int p1 , int p2 ) {
        if ( pos == s.size() ) return {1 , 0} ;

        auto key = make_tuple(pos , tight , started , p1 , p2) ;
        if (!tight && memo.count(key)) return memo[key] ;

        int lim = tight ? s[pos] - '0' : 9 ;

        Node res{0 , 0} ;
        
        for ( int d = 0 ; d <= lim ; d++ ) {
            int nt = tight && (d == lim) ;

            if (!started) {
                if ( d == 0 ) {
                    auto cur = dfs(pos + 1, nt , 0 , -1 , -1) ;
                    res.cnt += cur.cnt ;
                    res.wav += cur.wav ;     
                }else {
                    auto cur = dfs(pos + 1 , nt , 1 , d , -1) ;
                    res.cnt += cur.cnt ;
                    res.wav += cur.wav ;
                }
            }else {
                auto cur = dfs(pos + 1 , nt , 1 , d , p1 ) ;

                int add = 0 ;
                if ( p2 != -1 ) {
                    if ( (p1 > p2 && p1 > d) || (p1 < p2 && p1 < d) ) {
                        add = 1 ;
                    }
                }
                res.cnt += cur.cnt ;
                res.wav += cur.wav + cur.cnt * add ;
            }
        }
        if (!tight) memo[key] = res ;
        return res ;
    }

    ll solve ( long long x ){
        if (x < 0) return 0 ;
        s = to_string(x) ;
        memo.clear() ;
        return dfs(0 , 1 , 0 , -1 , -1).wav ; 
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1) ;
    }
};
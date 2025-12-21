class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq ;

        if ( a > 0 ) pq.push({a , 'a'}) ;
        if ( b > 0 ) pq.push({b , 'b'}) ;
        if ( c > 0 ) pq.push({c , 'c'}) ;

        string ans = "" ;
        while ( !pq.empty() ) {
            auto x = pq.top() ;
            pq.pop() ;
            int n =  ans.size() ;
            if ( n > 1 && ans[n - 1] == ans[n - 2] && ans[n - 1] == x.second ) {
                if ( pq.empty() ) break ;
                auto y = pq.top() ;
                pq.pop() ;
                ans += y.second ;
                y.first -= 1 ;
                if ( y.first != 0 ) {
                    pq.push({y.first , y.second}) ;
                }
            }else {
                ans += x.second ;
                x.first -= 1 ;
            }
            if ( x.first != 0 ) {
                pq.push({x.first , x.second}) ;
            }
        }
        return ans ;
    }
};
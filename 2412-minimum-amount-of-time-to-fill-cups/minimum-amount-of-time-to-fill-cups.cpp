class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0 ;
        priority_queue<int> pq ; // max - heap ;
        for (int x : amount ) {
            if ( x != 0 ) {
                pq.push(x) ;
            }
        }
        while ( !pq.empty() ) {
            int x = pq.top() ;
            pq.pop() ;

            if ( pq.empty() ) {
                ans += x ;
                break ;
            }

            int y = pq.top() ;
            pq.pop() ;

            x-- ;
            y-- ;
            ans++ ;

            if ( x != 0 ) pq.push(x) ;
            if ( y != 0 ) pq.push(y) ;
        }   
        return ans ;
    }
};
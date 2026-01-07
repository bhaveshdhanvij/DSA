class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size() ;
        int i = 0 , ans = 0 ;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;

        for ( i = 0 ; i < n ; i++ ) {

            if ( apples[i] > 0 ) {
                pq.push({i + days[i] , apples[i]}) ;
            }

            while ( !pq.empty() && pq.top().first <= i ) {
                pq.pop() ;
            }

            if (!pq.empty()) {
                auto a = pq.top() ; 
                pq.pop() ;

                int last = a.first , total = a.second ;
                total-- ;
                ans++ ;

                if ( total > 0 ) {
                    pq.push({last , total}) ;
                }
            }
        }

        while (!pq.empty()) {
            if ( pq.top().first <= i ) {
                pq.pop() ;
                continue ;
            }
            int last = pq.top().first , total = pq.top().second ;
            pq.pop() ;
            i++ ;
            ans++ ;
            total-- ;
            if ( total > 0 ) {
                pq.push({last , total}) ;
            }
        }
        return ans ;
    }
};
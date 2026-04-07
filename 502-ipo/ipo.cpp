class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size() ;
        vector<pair<int,int>> a(n) ;

        for ( int i = 0 ; i < n ; i++ ) {
            a[i] = { c[i] , p[i] } ;
        }

        sort ( a.begin() , a.end() ) ;
        // sort by increasing capital

        priority_queue<int> pq ;
        int i = 0 ;

        for ( int j = 0 ; j < k ; j++ ) {
            while ( i < n && a[i].first <= w ) {
                pq.push(a[i].second) ; // tracking profits 
                i++ ;
            }

            if ( pq.empty() ) break ;

            w += pq.top() ;
            pq.pop() ;
        }

        return w ;
    }
};
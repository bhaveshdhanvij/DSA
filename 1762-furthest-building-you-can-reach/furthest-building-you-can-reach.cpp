class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        priority_queue<int,vector<int>,greater<int>> pq ;
        int n = a.size() ;

        for ( int i = 1 ; i < n ; i++ ) {
            if ( a[i - 1] < a[i] ) {
                pq.push(a[i] - a[i - 1]) ;
                if ( pq.size() > l ) {
                    b -= pq.top() ;
                    pq.pop() ;
                } 
            }
            if ( b < 0 ) return i - 1 ;
        }

        return n - 1 ;
    }
};
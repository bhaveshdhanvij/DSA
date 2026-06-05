class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        sort ( a.begin() , a.end() , [](const vector<int> &x , const vector<int> &y) {
            return x[1] < y[1] ;
        });

        priority_queue<int> pq ;
        
        int total = 0 ;
        for ( auto x : a ) {
            int d = x[0] , last = x[1] ;
            
            total += d ;
            pq.push(d) ;
            
            if ( total > last ) {
                total -= pq.top() ;
                pq.pop() ;
            }
        }

        return pq.size() ;
    }
};
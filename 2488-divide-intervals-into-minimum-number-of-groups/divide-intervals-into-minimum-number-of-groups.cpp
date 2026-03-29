class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // TC : O(N log N) , SC : O(N) 

        sort ( intervals.begin() , intervals.end() ) ;
        priority_queue<int,vector<int>,greater<int>> pq ;
        for ( auto p : intervals ) {
            int st = p[0] ;
            int end = p[1] ;

            if ( !pq.empty() && pq.top() < st ) {
                pq.pop() ;
            }

            pq.push(end) ;
        }

        return pq.size() ;
    }
};
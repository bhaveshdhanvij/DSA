class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int,vector<int>,greater<int>> pq ;

        for ( int x : a ) {
            pq.push(x) ;
            if ( pq.size() > k ) pq.pop() ;
        }

        return pq.top() ;
    }
};
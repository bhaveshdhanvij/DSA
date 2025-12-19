class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Optimal Approach : Using Max Heap 
        // TC : O(NlogN) , SC : O(N) 
        
        priority_queue<int> pq ;
        for ( int x : stones ) pq.push(x) ;
        while (pq.size() > 1) {
            int x = pq.top() ; pq.pop() ;
            int y = pq.top() ; pq.pop() ;
            if ( x != y ) {
                pq.push(x - y) ;
            }
        }
        return pq.empty() ? 0 : pq.top() ;
    }
};
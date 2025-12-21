class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq ;
        for (int x : piles) {
            pq.push(x) ;
        }
        while (k--) {
            int s = pq.top() ;
            pq.pop() ;
            int d = s / 2 ;
            if ( s - d != 0 ) {
                pq.push(s - d) ;
            }
        }
        int ans = 0 ;
        while( !pq.empty() ) {
            ans += pq.top() ;
            pq.pop() ;
        }
        return ans ;
    }
};
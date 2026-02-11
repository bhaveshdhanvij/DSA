class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        priority_queue<int> pq ;
        long long ans = 0 ;

        for ( int x : a ) pq.push(x) ;
        
        while ( !pq.empty() && k > 0 ) {
            int t = pq.top() ;
            pq.pop() ;
            ans += t ;
            pq.push((t + 3 - 1) / 3) ;
            k-- ;
        } 

        return ans ;
        
    }
};
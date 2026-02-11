class Solution {
public:
    const int mod = 1e9 + 7 ;
    int maximumProduct(vector<int>& a, int k) {
        priority_queue<int,vector<int> ,greater<int>> pq ;
        for ( int x : a ) pq.push(x) ;

        while ( k > 0 ) {
            int x = pq.top() ;
            pq.pop() ;

            pq.push(++x) ;
            k-- ;
        }

        long long ans = 1 ;
        while ( !pq.empty() ) {
            int x = pq.top() ;
            ans = ( ans * (x % mod) ) % mod ;
            pq.pop() ;
        }

        return (int)ans ;
    }
};
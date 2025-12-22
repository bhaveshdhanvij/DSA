class Solution {
public:
    unordered_map<int,int> mp ; 

    int helper( int n ) {
        if ( n == 1 ) return 0 ;
        if ( mp.count(n) ) return mp[n] ;


        int next ;
        if ( n % 2 == 0 ) next = n / 2 ;
        else next = 3 * n + 1 ;

        return mp[n] = 1 + helper(next) ;
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>> pq ;
        for ( int x = lo ; x <= hi ; x++ ) {
            int p = helper(x) ;
            pq.push({p , x}) ;
            if ( pq.size() > k ) {
                pq.pop() ;
            }
        }
        return pq.top().second ;
    }
};
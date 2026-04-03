class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int,int>> pq ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            pq.push({a[i] - b[i] , i}) ;
        }
        
        int ans = 0 ;
        for ( int i = 0 ; i < k ; i++ ) {
            auto x = pq.top() ;
            pq.pop() ;

            ans += a[x.second] ;
        }

        while ( !pq.empty() ) {
            auto x = pq.top() ;
            pq.pop() ;

            ans += b[x.second] ;
        }

        return ans ;
    }
};
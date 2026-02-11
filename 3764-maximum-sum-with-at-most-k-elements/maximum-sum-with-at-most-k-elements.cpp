class Solution {
public:
    long long maxSum(vector<vector<int>>& a, vector<int>& l, int k) {
        priority_queue<int> pq ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            priority_queue<int,vector<int>,greater<int>> t ;
            for ( int j = 0 ; j < a[i].size() ; j++ ) {
                t.push(a[i][j]) ;
                if ( t.size() > l[i] ) {
                    t.pop() ;
                }
            }
            while ( !t.empty() ) {
                pq.push(t.top()) ;
                t.pop() ;
            }
        }

        long long ans = 0 ;
        while (!pq.empty() && k > 0 ) {
            ans += pq.top() ;
            pq.pop() ;
            k-- ;
        }

        return ans ;
    }
};
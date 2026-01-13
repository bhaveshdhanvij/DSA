class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        int ans = 0 ;
        queue<pair<int,int>> q ;
        int n = a.size() ;

        for ( int i = 0 ; i < n ; i++ ) {
            q.push({i , a[i]}) ;
        }

        while ( !q.empty() ) {
            auto curr = q.front() ;
            q.pop() ;
            ans++ ;
            
            int idx = curr.first ;
            int val = curr.second ;

            val-- ;
            if ( val == 0 && idx == k ) return ans ;

            if ( val > 0 ) {
                q.push({idx , val}) ;
            }

        }
        return ans ;
    }
};
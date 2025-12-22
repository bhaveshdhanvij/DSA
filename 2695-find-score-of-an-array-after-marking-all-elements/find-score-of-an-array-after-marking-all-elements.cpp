class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size() ;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq ;
        for ( int i = 0 ; i < n ; i++ ) {
            pq.push({nums[i] , i}) ;
        }
        vector<bool> vis(n , false) ;
        long long ans = 0 ;
        while ( !pq.empty() ) {

            auto x = pq.top() ;
            pq.pop() ;

            int i = x.second ;
            int num = x.first ;

            if ( vis[i] ) {
                continue ;
            }

            ans += num ;
            
            if ( i + 1 < n ) vis[i + 1] = true ;
            if ( i - 1 >= 0 ) vis[i - 1] = true ;
        }
        return ans ;
    }
};
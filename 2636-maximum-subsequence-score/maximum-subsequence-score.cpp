class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() ;
        vector<pair<int,int>> a ;
        for ( int i = 0 ; i < n ; i++ ) {
            a.push_back({nums2[i] , nums1[i]}) ;
        }
        sort ( a.rbegin() , a.rend() ) ;
        priority_queue<int,vector<int>,greater<int>> pq ;
        long long sum = 0 , ans = 0 ;
        for ( auto [x , y] : a ) {
            pq.push(y) ;
            sum += y ;

            if ( pq.size() > k ) {
                sum -= pq.top() ;
                pq.pop() ;
            }

            if ( pq.size() == k ) {
                ans = max ( ans , x * sum ) ;
            }
        }
        return ans ;
    }
};
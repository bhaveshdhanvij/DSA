class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        priority_queue<pair<int,int>> pq ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            auto vec = a[i] ;
            int curr = vec[0] * vec[0] + vec[1] * vec[1] ;

            pq.push({curr , i}) ;
            if ( pq.size() > k ) pq.pop() ;
        }

        vector<vector<int>> ans ;
        while ( !pq.empty() ) {
            int idx = pq.top().second ;
            pq.pop() ;

            ans.push_back(a[idx]) ;
        }

        return ans ;
    }
};
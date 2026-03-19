class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        priority_queue<int> pq ;
        vector<int> ans ;

        for ( auto e : q ) {
            pq.push(abs(e[0]) + abs(e[1])) ;
            if ( pq.size() > k ) {
                pq.pop() ;
            }

            if ( pq.size() == k ) ans.push_back(pq.top()) ;
            else ans.push_back(-1) ;
        }

        return ans ;
    }
};
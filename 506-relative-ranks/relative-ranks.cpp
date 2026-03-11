class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& a) {
        int n = a.size() ;
        
        priority_queue<pair<int,int>> pq ;
        for ( int i = 0 ; i < n ; i++ ) {
            pq.push({a[i] , i}) ;
        }

        vector<string> ans(n) ;
        int r = 1 ;

        while (!pq.empty()) {
            auto b = pq.top() ;
            pq.pop() ;

            int idx = b.second ;
            string val = to_string(r) ;

            if ( r == 1 ) val = "Gold Medal" ;
            else if ( r == 2 ) val = "Silver Medal" ;
            else if ( r == 3 ) val = "Bronze Medal" ;

            ans[idx] = val ;
            r++ ;
        }

        return ans ;
    }
};
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans ;
        deque<int> p ;

        for ( int i = 1 ; i <= m ; i++ ) {
            p.push_back(i) ;
        }
        
        for ( int i = 0 ; i < queries.size() ; i++ ) {
            int val = queries[i] , idx = -1 ;
            for ( int j = 0 ; j < p.size() ; j++ ) {
                if ( p[j] == val ) {
                    idx = j ;
                    break ;
                }
            } 
            p.erase(p.begin() + idx) ;
            p.push_front(val) ;
            ans.push_back(idx) ;
        }

        return ans ;
    }
};
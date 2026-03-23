class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& a) {
        // Approach : Basic simulation 
        int n = a.size() ;
        sort ( a.begin() , a.end() ) ;

        queue<int> q ;
        for ( int i = 0 ; i < n ; i++ ) q.push(i) ;

        vector<int> ans(n) ;
        for ( int c : a ) {
            int idx = q.front() ;
            q.pop() ;
            ans[idx] = c ;

            if (!q.empty()) {
                q.push(q.front()) ;
                q.pop() ;
            }
        }

        return ans ;
    }
};
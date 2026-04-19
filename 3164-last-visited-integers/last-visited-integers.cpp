class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& a) {
        vector<int> ans ;
        int k = 0 ;
        deque<int> seen ;
        
        for ( int x : a ) {
            if ( x != -1 ) {
                seen.push_front(x) ;
                k = 0 ;
            }else {
                k++ ;
                if ( k <= seen.size() ) {
                    ans.push_back(seen[k - 1]) ;
                }else {
                    ans.push_back(-1) ;
                }
            }
        }

        return ans ;
    }
};
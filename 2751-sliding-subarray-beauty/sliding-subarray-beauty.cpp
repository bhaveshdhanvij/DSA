class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& a, int k, int x) {
        multiset<int> m ;
        int l = 0 ;
        vector<int> ans ;
        for ( int r = 0 ; r < a.size() ; r++ ) {
            if ( a[r] < 0 ) {
                m.insert(a[r]) ;
            }

            if ( r - l + 1 == k ) {
                if ( m.size() < x ) {
                    ans.push_back(0) ;
                }else {
                    auto it = m.begin() ;
                    advance(it , x - 1) ;
                    int val = *it ;
                    ans.push_back(val) ;
                }

                if ( a[l] < 0 ) {
                    m.erase(m.find(a[l])) ;
                }
                l++ ;
            }
        }

        return ans ;
    }
};
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& a) {
        int n = a.size() ;
        vector<int> ans(n) ;

        for ( int i = 0 ; i < n ; i++ ) {
            int idx = ( (a[i] + i) % n + n) % n ;
            ans[i] = a[idx] ;
        }

        return ans ;
    }
};
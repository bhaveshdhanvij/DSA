class Solution {
public:
    int minimumCost(vector<int>& a) {
        int ans = 0 ;
        for ( int x : a ) ans += x ;
        sort ( a.rbegin() , a.rend() ) ;
        for ( int i = 2 ; i < a.size() ; i += 3 ) {
            ans -= a[i] ;
        }
        return ans ;
    }
};